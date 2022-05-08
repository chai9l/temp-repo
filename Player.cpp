#include "iostream"
#include <vector>
#include "Player.hpp"
#include <err.h>

using namespace std;

namespace coup
{

    void Player::income()
    {
        this->num_of_coins++;
    }
    void Player::foreign_aid()
    {
        this->num_of_coins += 2;
    }

    void Player::coup(Player &p)
    {
        if (this->num_of_coins < 7)
        {
            throw logic_error("Cannot use coup with less than 7 coins");
        }
        this->num_of_coins -= 7;
        p.num_of_coins = -1;
        p.lost = true;
    }

    int Player::coins()
    {
        return this->num_of_coins;
    }

    std::string Player::role()
    {
        return "Player";
    }
    string Player::get_name()
    {
        return this->name;
    }

    void Player::set_name(string name)
    {
        this->name = name;
    }

    void Player::set_num_of_coins(int num)
    {
        this->num_of_coins = num;
    }
}
