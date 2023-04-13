#pragma once
#include "string"
#include "game.hpp"
#include "card.hpp"
#include <exception>
#include <stdexcept>
#include <iostream>

namespace ariel {

    class Player {
        private:
            std::string _name;
            int numCards;
            int cardsWon;
        public:
            Player(const std::string& name);
            int stacksize();
            int cardesTaken();
            std::string getName();
            void setName(std::string name);
            int getNumCards();
            void setNumCards(int numCards);
            int getcardsWon();
            void setcardsWon(int cardsWon);
    };
}
