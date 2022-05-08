#include "iostream"
#include <vector>
#include "Ambassador.hpp"

namespace coup
{
    Ambassador::Ambassador(Game &game, const std::string &name) {
        this->set_name(name);
    }

    void Ambassador::transfer(Player &p1, Player &p2) {
        
    }

    void Ambassador::block(Player &p) {}

    Ambassador::~Ambassador() {}
}