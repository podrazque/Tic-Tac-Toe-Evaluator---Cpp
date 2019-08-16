#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Evaluate.h"

using namespace evaluator;

TEST_CASE("Check for X winner"){
    Evaluate board1("XXX....oo");
    Evaluate board2("..oXXXo..");
    Evaluate board3("oo....XXX");
    Evaluate board4("X..X.oXo.");
    Evaluate board5("oX..Xo.X.");
    Evaluate board6(".oX.oX..X");
    Evaluate board7("X..oXo..X");
    Evaluate board8("o.X.X.X.o");

    REQUIRE(board1.evaluateBoard() == Evaluate::Xwins);
    REQUIRE(board2.evaluateBoard() == Evaluate::Xwins);
    REQUIRE(board3.evaluateBoard() == Evaluate::Xwins);
    REQUIRE(board4.evaluateBoard() == Evaluate::Xwins);
    REQUIRE(board5.evaluateBoard() == Evaluate::Xwins);
    REQUIRE(board6.evaluateBoard() == Evaluate::Xwins);
    REQUIRE(board7.evaluateBoard() == Evaluate::Xwins);
    REQUIRE(board8.evaluateBoard() == Evaluate::Xwins);
}

TEST_CASE("Check for O winner"){
    Evaluate board1("OOOxx...x");
    Evaluate board2(".x.OOOxx.");
    Evaluate board3("x...xxOOO");
    Evaluate board4("OxxO..O.x");
    Evaluate board5("xOx.O..Ox");
    Evaluate board6("xxO..O.xO");
    Evaluate board7("O...OxxxO");
    Evaluate board8("..OxO.Oxx");

    REQUIRE(board1.evaluateBoard() == Evaluate::Owins);
    REQUIRE(board2.evaluateBoard() == Evaluate::Owins);
    REQUIRE(board3.evaluateBoard() == Evaluate::Owins);
    REQUIRE(board4.evaluateBoard() == Evaluate::Owins);
    REQUIRE(board5.evaluateBoard() == Evaluate::Owins);
    REQUIRE(board6.evaluateBoard() == Evaluate::Owins);
    REQUIRE(board7.evaluateBoard() == Evaluate::Owins);
    REQUIRE(board8.evaluateBoard() == Evaluate::Owins);
}

TEST_CASE("No winner"){
    Evaluate board1("OO...X..x");
    Evaluate board2("x..x..oox");
    Evaluate board3("x.x.oo.ox");
    Evaluate board4(".........");
    Evaluate board5("oxox.....");
    Evaluate board6("ooxx.....");
    Evaluate board7("\n\n\n\n\n\n\n\n\n");
    Evaluate board8("ox.x.xo.o");
    Evaluate board9("         ");

    REQUIRE(board1.evaluateBoard() == Evaluate::NoWinner);
    REQUIRE(board2.evaluateBoard() == Evaluate::NoWinner);
    REQUIRE(board3.evaluateBoard() == Evaluate::NoWinner);
    REQUIRE(board4.evaluateBoard() == Evaluate::NoWinner);
    REQUIRE(board5.evaluateBoard() == Evaluate::NoWinner);
    REQUIRE(board6.evaluateBoard() == Evaluate::NoWinner);
    REQUIRE(board7.evaluateBoard() == Evaluate::NoWinner);
    REQUIRE(board8.evaluateBoard() == Evaluate::NoWinner);
    REQUIRE(board9.evaluateBoard() == Evaluate::NoWinner);
}

TEST_CASE("Unreachable state"){
    Evaluate board1("OOO..X..x");
    Evaluate board2("x..xx.oox");
    Evaluate board3("xxx.oo.o.");
    Evaluate board4("OOOXX....");
    Evaluate board5("XXXXXXXXX");
    Evaluate board6("OOOOOOOOO");
    Evaluate board7("OOO.X.X..");
    Evaluate board8("O..OX.X.O");
    Evaluate board9("OO.OX.X..");
    Evaluate board10("O........");
    Evaluate board11("OOOoooOOO");
    Evaluate board12("xxxXXXxxx");

    REQUIRE(board1.evaluateBoard() == Evaluate::UnreachableState);
    REQUIRE(board2.evaluateBoard() == Evaluate::UnreachableState);
    REQUIRE(board3.evaluateBoard() == Evaluate::UnreachableState);
    REQUIRE(board4.evaluateBoard() == Evaluate::UnreachableState);
    REQUIRE(board5.evaluateBoard() == Evaluate::UnreachableState);
    REQUIRE(board6.evaluateBoard() == Evaluate::UnreachableState);
    REQUIRE(board7.evaluateBoard() == Evaluate::UnreachableState);
    REQUIRE(board8.evaluateBoard() == Evaluate::UnreachableState);
    REQUIRE(board9.evaluateBoard() == Evaluate::UnreachableState);
    REQUIRE(board10.evaluateBoard() == Evaluate::UnreachableState);
    REQUIRE(board11.evaluateBoard() == Evaluate::UnreachableState);
    REQUIRE(board12.evaluateBoard() == Evaluate::UnreachableState);
}

TEST_CASE("Invalid Input"){
    Evaluate board1("123412");
    Evaluate board2("IyouhateJava");

    REQUIRE(board1.evaluateBoard() == Evaluate::InvalidInput);
    REQUIRE(board2.evaluateBoard() == Evaluate::InvalidInput);
}
