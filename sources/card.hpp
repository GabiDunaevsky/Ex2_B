#pragma once
#include "string"
#include "game.hpp"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <iterator>




namespace ariel {
    class Card{
        private:
            int numCard;
            std::string shape;
        public:
         Card getCard();
         void setCard(int numCard,std::string shape);
         void setnumCard(int num);
         int getnumCard();
         void setshape(std::string shape);
         std::string getshape();
    };

}