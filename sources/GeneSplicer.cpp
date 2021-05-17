#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;
const int num_cards = 5;

Player &GeneSplicer::discover_cure(Color c)
{
    if (!board.is_found_cure(c))
    {
        if (!board.is_research_stations(this->city))
        {
            throw std::invalid_argument{"There is no research station in this city"};
        }
        int count = cards.size();
        if (count < num_cards)
        {
            throw std::invalid_argument{"There are not enough cards"};
        }
        int count2=num_cards;
        auto it = cards.begin();
        while (it != cards.end() && count2 > 0)
        {
            it = cards.erase(it);
            count2--;
            it++;
        }
        board.insert_cures(c);
    }
    return *this;
};
