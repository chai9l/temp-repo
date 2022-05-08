#include "Game.hpp"
#include <string>
#pragma once

namespace coup{
    class Player{
        private:
        std::string name;
        int num_of_coins;

        public:
        void income();
        void foreign_aid();
        void coup(Player &p);
        std::string role();
        int coins();
    };
}