#include "Medic.hpp"

using namespace std;
using namespace pandemic;

Player &Medic::treat(City c)
{
    if (this->city != c)
    {
        throw std::invalid_argument{"You're not in the right city"};
    }
    if (board[c] == 0)
    {
        throw std::invalid_argument{"There is nothing to cure anymore"};
    }
    board[c] = 0;

    return *this;
}

void Medic::treat_medic()
{

    if(board.is_found_cure(Board::get_city_color(this->city)))
    {
        board[this->city]=0;
    }
}