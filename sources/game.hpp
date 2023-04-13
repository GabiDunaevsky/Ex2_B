#pragma once
#include "vector"
#include "string"
#include <exception>
#include <stdexcept>
#include <iostream>
#include "player.hpp"
#include "card.hpp"
#include <vector>
namespace ariel{
    class Player;
    class Card;
    class Game{
        private:
            std::string playerName1;
            std::string playerName2;
            std::string lastturn;
            std::string allturns;
            bool gameOver;
            int numCardsplayer1;
            int numCardsplayer2;
            int firstRound;
            Player *pl1;
            Player *pl2;
            std::vector<Card> player1Cards;
            std::vector<Card> player2Cards;
            double numberOfWinsP1;
            double numberOfWinsP2;
            int numberOfDraws;
            double numberTurnsPlayed;
        public:
            Game(Player &p1,Player &p2);
            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
            std::string getPlayerName1();
            void setPlayerName1(std::string name);
            std::string getPlayerName2();
            void setPlayerName2(std::string name);
            std::string getWinner();
            void setWinner(std::string name);
            std::string getLastTurn();
            void setLastTurn(std::string lastTurn);
            std::string getAllTurns();
            void setAllTurns(std::string allTurns);
            void dealCards();
            std::string numCardToString(int num);
    };
}
