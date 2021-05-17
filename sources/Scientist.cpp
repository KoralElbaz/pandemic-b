#include "Scientist.hpp"
using namespace std;
using namespace pandemic;

Player &Scientist::discover_cure(Color c)
{
    if (!board.is_found_cure(c))
    {
        if (!board.is_research_stations(this->city))
        {
            throw std::invalid_argument{"There is no research station in this city"};
        }

        int count = 0;
        for (const auto &t : cards)
        {
            if (Board::get_city_color(t) == c)
            {
                count++;
            }
        }
        if (count < this->n)
        {
            throw std::invalid_argument{"There are not enough cards"};
        }

        int count2 = n;
        auto it = cards.begin();
        while (it != cards.end() && count2 > 0)
        {
            if (Board::get_city_color(*it) == c)
            {
                it = cards.erase(it);
                count2--;
            }
            else
            {
                it--;
            }
        }
        board.insert_cures(c);
    }
    return *this;
};