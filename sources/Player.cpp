
#include "Player.hpp"

using namespace std;
using namespace pandemic;
const int num_cards = 5;


//-----------------Drive-------------------//
//we can drive from city to diffrent city only if thay are connected 
//-----------------------------------------//
Player &Player::drive(City c)
{
    if(this->city==c){
        throw invalid_argument{"Is not possible to drive to the city where you are already "};
    }
    if (!board.isConnect(this->city, c))
    {
        throw invalid_argument{"The Cities are not directly connected"};
    }
    this->city = c;
    treat_medic();
    return *this;
}

//-----------------Fly Direct-------------------//
//we can fly Direct from city to diffrent city only if we have card of the city c. 
//-----------------------------------------//
Player &Player::fly_direct(City c)
{
    if(this->city==c){
        throw invalid_argument{"Is not possible to fly to the city where you are already "};
    }
    if (cards.count(c) == 0)
    {
        throw invalid_argument{"Illegal action , you dont have this card"};
    }
    cards.erase(c);
    this->city = c;
    treat_medic();
    return *this;
}

//-----------------Fly Charter-------------------//
//we can fly Direct from city to diffrent city only if we have card of the current city . 
//-----------------------------------------//
Player &Player::fly_charter(City c)
{
    if(this->city==c){
        throw invalid_argument{"Is not possible to fly to the city where you are already "};
    }
    if (cards.count(this->city) == 0)
    {
        throw invalid_argument{"Illegal action , you dont have this card "};
    }
    cards.erase(this->city);
    this->city = c;
    treat_medic();
    return *this;
}

//-----------------Fly Shuttle-------------------//
//we can fly Direct from city to diffrent city only if we have research station of the current city/fly to city 
//-----------------------------------------//
Player &Player::fly_shuttle(City c)
{
    if(this->city==c){
        throw invalid_argument{"Is not possible to fly to the city where you are already "};
    }
    if (!board.is_research_stations(this->city) || !board.is_research_stations(c))
    {
        throw invalid_argument{"there is no research station in this city "};
    }
    this->city = c;
    treat_medic();
    return *this;
}

//-----------------build-------------------//
//we can build research station only if we have card of the current city
//-----------------------------------------//
Player &Player::build()
{
    if (cards.count(this->city) == 0)
    {
        throw invalid_argument{"Illegal action , you dont have this card"};
    }
    if (!board.is_research_stations(this->city))
    {
        board.build_research_stations(this->city);
        cards.erase(this->city);
    }
    return *this;
}

//-----------------Discover Cure-------------------//
/**
 * in order to find a cure for the disease we need:
 * if there is alrady a cure for this color (c) && 
 * if the current city has a research station &&
 * we need to go through a list of cards and to check if we have 5 cards with the same color.
 * 
 * after all we need to remove all this 5 cards.
 * */
//-----------------------------------------//
Player &Player::discover_cure(Color c)
{
    if (board.is_found_cure(c))
    {
        return *this;
    }
    if (!board.is_research_stations(this->city))
    {
        throw invalid_argument{"Illegal action , you dont have this card"};
    }
    int count = 0;
    for (const auto &t : cards)
    {
        if (Board::get_city_color(t) == c)
        {
            count++;
        }
    }
    if (count < num_cards)
    {
        throw invalid_argument{"There are not enough cards with the same color"};
    }
    
    int count2=num_cards; //5
    auto it = cards.begin();
    while (it != cards.end() && count2>0)
    {
            if (Board::get_city_color(*it) == c)
            {
                it=cards.erase(it);
                count2--;
            }
            else{
                ++it;
            }
    }
    board.insert_cures(c);
    return *this;

}


//------------------- Treat ---------------------//
/**we can treat the disease of this city (c) if:
 *if we are in c && if there is something to take care of
*/
//-----------------------------------------//
Player &Player::treat(City c)
{
     if (this->city != c)
    {
        throw invalid_argument{"Illegal action , Shpuld be in the current city"};
    }
    if(board[c]==0)
    {
        throw invalid_argument{"The city is free of disease"};
    }

    if (board.is_found_cure(Board::get_city_color(c)))
    {
        board[c]=0;
    }
    else{
        board[c]--;
    }
    return *this;
}

//------------------- Take Card ---------------------//
//we can take card of c 
//-----------------------------------------//
Player &Player::take_card(City c)
{
    cards.insert(c);
    return *this;
}
