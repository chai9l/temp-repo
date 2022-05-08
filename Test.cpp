#include "doctest.h"
#include "Game.hpp"
#include "Player.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include <string>
#include "vector"
using namespace coup;

TEST_CASE("Game 1")
{
    Game game_1{};
    Captain captain{game_1, "Captain"};
    Duke duke{game_1, "Duke"};
    Assassin assassin{game_1, "Assasin"};
    Ambassador ambassador{game_1, "Ambassador"};
    Contessa contessa{game_1, "Contessa"};

    CHECK(game_1.players().size() == 5);

    CHECK(captain.role() == "captain");
    CHECK(contessa.role() == "contessa");
    CHECK(duke.role() == "duke");
    CHECK(assassin.role() == "assassin");
    CHECK(ambassador.role() == "ambassador");

    // ROUND 1
    CHECK_NOTHROW(captain.foreign_aid());
    CHECK_NOTHROW(duke.tax());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(contessa.income());

    CHECK(captain.coins() == 2);
    CHECK(duke.coins() == 3);
    CHECK(assassin.coins() == 1);
    CHECK(ambassador.coins() == 1);
    CHECK(contessa.coins() == 1);

    // ROUND 2
    CHECK_NOTHROW(duke.foreign_aid());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_NOTHROW(ambassador.foreign_aid());
    CHECK_NOTHROW(captain.foreign_aid());
    CHECK_NOTHROW(contessa.foreign_aid());

    CHECK(captain.coins() == 4);
    CHECK(duke.coins() == 5);
    CHECK(assassin.coins() == 3);
    CHECK(ambassador.coins() == 3);
    CHECK(contessa.coins() == 3);

    // ROUND 3
    CHECK_NOTHROW(captain.steal(contessa));
    CHECK_NOTHROW(duke.tax());
    CHECK_NOTHROW(assassin.assinate(ambassador));
    CHECK_THROWS(ambassador.transfer(duke, captain));
    CHECK_NOTHROW(contessa.block(assassin));

    CHECK(captain.coins() == 6);
    CHECK(duke.coins() == 8);
    CHECK(assassin.coins() == 0);
    CHECK(ambassador.coins() == 3);
    CHECK(contessa.coins() == 1);

    // ROUND 4
    CHECK_NOTHROW(captain.foreign_aid());
    CHECK_NOTHROW(duke.coup(captain));
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_NOTHROW(ambassador.block(assassin));
    CHECK_NOTHROW(contessa.foreign_aid());

    CHECK(captain.coins() == 0);
    CHECK(duke.coins() == 1);
    CHECK(assassin.coins() == 0);
    CHECK(ambassador.coins() == 3);
    CHECK(contessa.coins() == 3);

    // ROUND 5

    // Captain out of the game
    CHECK_THROWS(captain.income());
    CHECK_THROWS(captain.steal(duke));
    CHECK_THROWS(captain.foreign_aid());
    CHECK_THROWS(captain.coup(duke));
    
    CHECK_NOTHROW(duke.tax());
    // Assassin has 0 coins /////////////
    CHECK_THROWS(assassin.assinate(duke));
    /////////////////////////////////////
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(ambassador.foreign_aid());
    CHECK_NOTHROW(contessa.foreign_aid());

    CHECK(captain.coins() == -1);
    CHECK(duke.coins() == 4);
    CHECK(assassin.coins() == 1);
    CHECK(ambassador.coins() == 5);
    CHECK(contessa.coins() == 5);

    // ROUND 6
    CHECK_NOTHROW(duke.tax());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_NOTHROW(ambassador.transfer(assassin, contessa));
    CHECK_NOTHROW(contessa.income());

    CHECK(duke.coins() == 7);
    CHECK(assassin.coins() == 2);
    CHECK(ambassador.coins() == 5);
    CHECK(contessa.coins() == 7);

    // ROUND 7
    CHECK_NOTHROW(duke.coup(contessa));
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(ambassador.foreign_aid());
    
    CHECK(duke.coins() == 0);
    CHECK(assassin.coins() == 3);
    CHECK(ambassador.coins() == 7);
    CHECK(contessa.coins() == -1);

    // ROUND 8
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.assinate(duke));
    CHECK_NOTHROW(ambassador.coup(assassin));

    CHECK(duke.coins() == -1);
    CHECK(assassin.coins() == -1);
    CHECK(ambassador.coins() == 0);
    // ambassador won the game !

    CHECK_THROWS(duke.tax());
}
