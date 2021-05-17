#include "Dispatcher.hpp"
using namespace std;
using namespace pandemic;

Player &Dispatcher::fly_direct(City c)
{
    if (this->city == c)
    {
        throw invalid_argument{"Is not possible to fly to the city where you are already "};
    }
    if (board.is_research_stations(this->city))
    {
        this->city = c;
    }
    else
    {
        return Player::fly_direct(c);
    }
    return *this;
};