#pragma once
#include <iostream>
#include <ostream>
#include <string>
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>

namespace pandemic
{

    class Board
    {
        static std::map<City, std::set<City>> connected; //Connections between cities
        std::map<City, int> infection_level;             // Number disease levels in a specific city
        std::set<City> list_research_stations;           //List of research stations by city
        std::set<Color> find_cure;                       //The color of a city where there is medicine

    public:
        Board() {}
        int &operator[](City c);
        friend std::ostream &operator<<(std::ostream &os, const Board &c);
        bool is_clean();
        void remove_cures() { find_cure.clear(); };
        void remove_stations() { list_research_stations.clear(); };


        //-----------------help function----------------//
        /** 
         * isConnect- Checks if the cities are directly connected
         * build_research_stations-insert city to the strcut "list_research_stations" its mine that there is a research station in this ciry
         * is_research_stations-check if there is a research station in this city
         * get_city_color-find what color have in this city
         * is_found_cure-check if we found mediction in this city
         * insert_cures-if we are found mediction its should be noted
         * */
        //---------------------------------------------//

        bool isConnect(City &city1, City &city2) { return connected.at(city1).count(city2) != 0; };
        void build_research_stations(City c) { list_research_stations.insert(c); };
        bool is_research_stations(City c) { return (list_research_stations.count(c) != 0); };
        static Color get_city_color(City c){return color_of_city.at(c);};
        bool is_found_cure(Color c) { return (find_cure.count(c) != 0); };
        void insert_cures(Color c) { find_cure.insert(c); };
    };
}