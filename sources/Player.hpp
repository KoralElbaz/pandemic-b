#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

namespace pandemic
{

    class Player
    {
        protected:
            Board& board; // Each player must specify his or her game board
            std::set<City> cards;//Each player should be noted the cards in his possession
            City city;//Position of the player on the game board
            std::string role_player;//The role of the player

        public:
    //constructor with initialization
        Player(Board& board, City city, std::string role):board(board), city(city), role_player(role){}

        Player& drive(City c);
        virtual Player& fly_direct(City c);
        Player& fly_charter(City c);
        Player& fly_shuttle(City c);
        virtual Player& build();
        virtual Player& discover_cure(Color c);
        virtual Player& treat(City c);
        Player& take_card(City c);
        std::string role(){return role_player;};
        void remove_cards(){cards.clear();};

        virtual void treat_medic(){}; 
    };
}