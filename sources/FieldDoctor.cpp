#include "FieldDoctor.hpp"

using namespace std;
using namespace pandemic;

Player &FieldDoctor::treat(City c)
{
  
    if (!board.isConnect(this->city, c) && this->city != c)
    {
        throw std::invalid_argument{"It is not possible to reach this city"};
    }
    if (board[c] == 0)
    {
        throw std::invalid_argument{"There is nothing to cure anymore"};
    }

    if (board.is_found_cure(Board::get_city_color(c)))
    {
        board[c] = 0;
    }
    else
    {
        board[c]--;
    }

    return *this;
};
