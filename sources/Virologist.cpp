#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

Player &Virologist::treat(City c)
{

    if (this->city != c)
    {
        if (cards.count(c) == 0)
        {
            throw std::invalid_argument{"Illegal action , you dont have this card"};
        }
        cards.erase(c);
    }
    else if (board[c] == 0)
    {
        throw std::invalid_argument{"There is nothing to cure anymore"};
    }
    else if (board.is_found_cure(Board::get_city_color(c)))
    {
        board[c] = 0;
        return *this;
    }
    board[c]--;
    return *this;
};