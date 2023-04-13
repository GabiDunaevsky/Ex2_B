#include "player.hpp"
#include "game.hpp"
#include "exception"
#include <exception>
#include <stdexcept>
#include <iostream>

namespace ariel{
    Player::Player(const std::string& name){
        this->_name = name;
        this->numCards = 0;
        this->cardsWon = 0;
    }
    int Player::stacksize(){
        if(numCards > 26 || numCards < 0){
            throw std::invalid_argument("can't have more than 52 or less then 0");
        }
        return this->numCards;

    }
    int Player::cardesTaken(){
        if(cardsWon < 0){
            throw std::invalid_argument("cna't be less then 0");
        }
        return this->cardsWon;
    }
    std::string Player::getName(){
        return this->_name;
    }
    void Player::setName(std::string name){
        this->_name = name;
    }
    int Player::getNumCards(){
        return this->numCards;
    }
    void Player::setNumCards(int numCards){
        this->numCards = numCards;
    }
    int Player::getcardsWon(){
        return this->cardsWon;
    }
    void Player::setcardsWon(int cardsWon){
        this->cardsWon = cardsWon;
    }

}