#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
#include "exception"
#include <exception>
#include <stdexcept>
#include <iostream>
namespace ariel{
    Card Card::getCard(){
        return *this;
    }
    void Card::setCard(int num,std::string shape){
        // if(num > 13 || num <= 0 ){
        //     throw std::invalid_argument("card number is wrong");
        // }
        // if(color != 0 || color != 1){
        //     throw std::invalid_argument("card color is wrong");
        // }

        // if(shape != "Clubs" || shape != "Diamond" || shape != "Heart" || shape != "Spades"){
        //     throw std::invalid_argument("There is no such shape");
        // }
        // this->color = color;
        this->shape = shape;
        this->numCard = num;
    }
    void Card::setnumCard(int num){
        this->numCard = num;
    }
    int Card::getnumCard(){
        return this->numCard;
    }
    void Card::setshape(std::string shape){
        this->shape = shape;
    }
    std::string Card::getshape(){
        return this->shape;
    }

}