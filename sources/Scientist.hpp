#pragma once

#include "Player.hpp"
namespace pandemic
{

    class Scientist:public Player
    {
        int n;

    public:
        Scientist(Board& b, City c, int n): Player(b, c, "Scientist"), n(n) {}
    
        Player& discover_cure(Color c)override;
    };
}