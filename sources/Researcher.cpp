#include "Researcher.hpp"

using namespace std;
using namespace pandemic;
const int num_cards = 5;


Player& Researcher::discover_cure(Color c) {
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
        throw std::invalid_argument{"There are not enough cards"};
    }
    if (board.is_found_cure(c))
    {
        return *this;
    }

    int count2=num_cards;
    auto it = cards.begin();
    while (it != cards.end() && count2>0)
    {
            if (Board::get_city_color(*it) == c)
            {
                it=cards.erase(it);
                count2--;
            }
            else{
                it--;
            }
    }
    board.insert_cures(c);
    return *this;
    };