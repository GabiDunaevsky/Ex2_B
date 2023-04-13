#include "exception"
#include "vector"
#include <exception>
#include <stdexcept>
#include <iostream>
#include "game.hpp"
#include "player.hpp"
using namespace std;

/*
For this task i was using a lot of sources:
 https://www.tutorialspoint.com/cplusplus/cpp_function_call_by_pointer.htm
 https://www.scaler.com/topics/pointer-to-object-in-cpp/
 https://www.bitdegree.org/learn/random-number-generator-cpp
 https://cplusplus.com/reference/algorithm/random_shuffle/
 https://stackoverflow.com/questions/39752068/multiple-linking-c-files
 https://cplusplus.com/reference/vector/vector/size/
 https://cplusplus.com/reference/vector/vector/erase/
 https://cplusplus.com/reference/cstdlib/rand/
 https://www.tutorialspoint.com/cpp_standard_library/cpp_vector_clear.htm
 https://www.w3schools.com/cpp/cpp_function_reference.asp
 https://www.geeksforgeeks.org/destructors-c/
 https://www.techiedelight.com/remove-range-elements-vector-cpp/

 I was also using the help of chat GPT for this task ( only for question i wrote every thig by myself).
*/

namespace ariel {


//Initialize the values of the game.
    Game::Game(Player &p1,Player &p2){
        this->playerName1 = p1.getName();
        this->playerName2 = p2.getName();
        this->lastturn = "";
        this->allturns = "";
        this->gameOver = 0;
        this->firstRound = 1;
        dealCards();
        pl1 = &p1;
        pl2 = &p2;
        this->numberOfWinsP1 = 0;// initialize for every player before the game
        this->numberOfWinsP2 = 0;// initialize for every player before the game
        this->numberOfDraws = 0;// initialize for every player before the game
        this->numberTurnsPlayed = 0;// initialize for every player before the game
        this->pl1->setcardsWon(0);// initialize for every player before the game
        this->pl2->setcardsWon(0);// initialize for every player before the game
        this->pl1->setNumCards(this->player1Cards.size());// initialize for every player before the game
        this->pl2->setNumCards(this->player2Cards.size());// initialize for every player before the game
        this->numCardsplayer1 = p1.getNumCards();// initialize for every player before the game, say how much cards he has currently.
        this->numCardsplayer2 = p2.getNumCards();// initialize for every player before the game, say how much cards he has currently.
    }
    /*
    This is the biggest and the most importent function in the program. In this function a turn is played and the winner takes his cards.
    In ecey step(win or draw) the information about the game and about every player is updated.
    */
    void Game::playTurn(){
       if(this->pl1 == this->pl2){
         throw std::invalid_argument("player can't play agains him self");
       }
       this->lastturn = "";
       int turnWinner = 0;
       int warPos = 0;
       std::vector<int>::size_type warPosV = 0;
       while (turnWinner == 0)
       {
            int cWon = ((warPos + 1) * 2);
            if(this->numCardsplayer1 <= 0 || this->numCardsplayer2 <= 0){
                    this->gameOver = 1;
            }
            if(player1Cards.size() <= 0 || player2Cards.size() <= 0){
                this->gameOver = 1;
            }
            
            if(this->gameOver == 1){
                throw std::invalid_argument("game is over can't play another round");
            }
            string cardNameP1 = this->numCardToString(player1Cards[warPosV].getnumCard());// For the printings
            string cardNameP2 = this->numCardToString(player2Cards[warPosV].getnumCard());// For the printings
            this->lastturn = this->lastturn + playerName1 + " played " + cardNameP1+ " of " + player1Cards[warPosV].getshape() + " " + playerName2 + " played " + cardNameP2 + " of " + player2Cards[warPosV].getshape() +". ";
            if(player1Cards[warPosV].getnumCard() > player2Cards[warPosV].getnumCard()){
                //Checking the case that we are dealin with As and 2.
                if(player1Cards[warPosV].getnumCard() == 14 && player2Cards[warPosV].getnumCard()  == 2){
                    numCardsplayer2 = numCardsplayer2 + (1+warPos);
                    numCardsplayer1 = numCardsplayer1 - (1+warPos);
                    this->pl2->setcardsWon(this->pl2->getcardsWon() + cWon);
                    this->numberOfWinsP2++;
                    turnWinner = 1;
                    this->lastturn = this->lastturn + playerName2 + " wins.";
                }else{
                    numCardsplayer2 = numCardsplayer2 - (1+warPos);
                    numCardsplayer1 = numCardsplayer1 + (1+warPos);
                    this->pl1->setcardsWon(this->pl1->getcardsWon() + cWon);
                    this->numberOfWinsP1++;
                    turnWinner = 1;
                    this->lastturn = this->lastturn + playerName1 + " wins.";
            }
            }else if (player2Cards[warPosV].getnumCard() > player1Cards[warPosV].getnumCard())
            {
                //Checking the case that we are dealin with As and 2.
                if(player2Cards[warPosV].getnumCard() == 14 && player1Cards[warPosV].getnumCard() == 2){
                    numCardsplayer2 = numCardsplayer2 - (1+warPos);
                    numCardsplayer1 = numCardsplayer1 + (1+warPos);
                    this->pl1->setcardsWon(this->pl1->getcardsWon() + cWon);
                    this->numberOfWinsP1++;
                    turnWinner = 1;
                    this->lastturn = this->lastturn + playerName1 + " wins.";
                }else{
                    numCardsplayer2 = numCardsplayer2 + (1+warPos);
                    numCardsplayer1 = numCardsplayer1 - (1+warPos);
                    this->pl2->setcardsWon(this->pl2->getcardsWon() + cWon);
                    this->numberOfWinsP2++;
                    turnWinner = 1;
                    this->lastturn = this->lastturn + playerName2 + " wins.";
                }
            }else{// draw'
                warPos += 2;
                warPosV += 2;
                this->lastturn = this->lastturn + "draw. ";
                this->numberOfDraws++;
                if(warPos >= player1Cards.size() || warPos >= player2Cards.size()){
                    if(this->player1Cards.size() != 0){
                        numCardsplayer1 = numCardsplayer1 + (int)player1Cards.size();
                        this->pl1->setcardsWon(this->pl1->getcardsWon() + static_cast<int>(player1Cards.size()));
                        player1Cards.clear();
                    }
                    if(this->player2Cards.size() != 0){
                        numCardsplayer2 = numCardsplayer2 + (int)player2Cards.size();
                        this->pl2->setcardsWon(this->pl2->getcardsWon() + static_cast<int>(player2Cards.size()));
                        player2Cards.clear();
                    }
                    gameOver = 1;
                    turnWinner = 1;
                    break; 
                }
            }   
       }
       if(warPos + 1 <= player1Cards.size() && warPos + 1 <= player2Cards.size()){
          player1Cards.erase(player1Cards.begin(),player1Cards.begin() + warPos + 1);
          player2Cards.erase(player2Cards.begin(), player2Cards.begin() + warPos + 1);
       }
       
       numberTurnsPlayed++;
       this->firstRound = 0;
       this->pl1->setNumCards(this->player1Cards.size());
       this->pl2->setNumCards(this->player2Cards.size());
       this->allturns = this->allturns + this->lastturn + "\n";
    }
    /*
    This finction is an helper function for the printings that converting numbers to the correct printing.
    */
    std::string Game::numCardToString(int num){
        if(num >= 2 && num <= 10){
            return to_string(num);
        }else if (num == 11)
        {
            return "Jack";
        }else if(num == 12){
            return "Queen";
        }else if (num == 13)
        {
            return "King";
        }else{
            return "As";
        }
    }
    // print the last turn as a string
    void Game::printLastTurn(){
        if (this->firstRound == 1)
        {
            throw std::invalid_argument("Didn't play yet, can't print the last round");
        }
        
        cout << this->lastturn << endl;
    }
    //Playing all the turns.
    void Game::playAll(){
        // if(gameOver == 1){
        // throw std::invalid_argument("game is over can't play another round");
    //    }
       while (gameOver == 0 && player1Cards.size() > 0 && player2Cards.size() > 0)
       {
        this->playTurn();
       }
       //This to ifs are just to make sure that after all turns are played the stack of every player is empty and he took all the cards he won.
       if(this->player1Cards.size() != 0){
         numCardsplayer1 = numCardsplayer1 + (int)player1Cards.size();
         this->pl1->setcardsWon(this->pl1->getcardsWon() + static_cast<int>(player1Cards.size()));
         player1Cards.clear();
       }
       if(this->player2Cards.size() != 0){
         numCardsplayer2 = numCardsplayer2 + (int)player2Cards.size();
         this->pl2->setcardsWon(this->pl2->getcardsWon() + static_cast<int>(player2Cards.size()));
         player2Cards.clear();
       }
       this->pl1->setNumCards(this->player1Cards.size());
       this->pl2->setNumCards(this->player2Cards.size());
       this->gameOver = 1;
    }
    //Prints the winner, the player who has mor cards.
    void Game::printWiner(){
    //     if(gameOver == 0){
    //     throw std::invalid_argument("game is  not over there isnt a winner");
    //    }
    //    if (this->winner == "")
    //    {
    //     throw std::invalid_argument("There is no a winner yet");
    //    }
       
        if(this->numCardsplayer1 > this->numCardsplayer2){
            cout << this->playerName1 << endl;
        }else if(this->numCardsplayer1 < this->numCardsplayer2){
            cout << this->playerName2 << endl;
        }else{
            cout << "draw" << endl;
        }
    }
    //printing all the turns of the game by line.
    void Game::printLog(){
        if (this->firstRound == 1)
        {
            throw std::invalid_argument("Didnt play yet, can't print the last round");
        }
        cout << this->allturns << endl;
    }
    //Prints all the stats to each player.
    void Game::printStats(){
            cout << "name: " + this->playerName1 << endl;
            double p1WinRate = (double)(this->numberOfWinsP1/this->numberTurnsPlayed);
            cout << "  win rate: " << p1WinRate << endl;
            cout << "  cards won: " << to_string(pl1->getcardsWon()) << endl;
            cout << "  draw rate: " << to_string(numberOfDraws/numberTurnsPlayed) << endl;
            cout << "  anount of draws: " << to_string(numberOfDraws)<< endl;
            cout << "name: " + this->playerName2 << endl;
            cout << "  win rate: " << to_string(this->numberOfWinsP2/numberTurnsPlayed) << endl;
            cout << "  cards won: " << to_string(pl1->getcardsWon()) << endl;
            cout << "  draw rate: " << to_string(numberOfDraws/numberTurnsPlayed) << endl;
            cout << "  amount of draws: " << to_string(numberOfDraws) << endl;
    }

    std::string Game::getPlayerName1(){
        return this->playerName1;
    }
    void Game::setPlayerName1(std::string name){
        this->playerName1 = name;
    }
    std::string Game::getPlayerName2(){
        return this->playerName2;
    }
    void Game::setPlayerName2(std::string name){
        this->playerName2 = name;
    }
    std::string Game::getLastTurn(){
        return this->lastturn;
    }
    void Game::setLastTurn(std::string lastTurn){
        this->lastturn = lastTurn;
    }
    std::string Game::getAllTurns(){
        return this->allturns;
    }
    void Game::setAllTurns(std::string allTurns){
        this->allturns = allTurns;
    }
    // This function randomly dealing cards to each player, every one are getting 26 at the biggining of the game.
    void Game::dealCards(){     /// 0 = heart 1 = "Diamond" , 2 = "Spades" , 3 ="Clubs"
        int shape = 0;
        int counterCardNUmber = 1; //As is 14.
        srand((unsigned) time(0)); 
        for(int i = 0 ; i < 52; i++){ 
            Card tmp;
            double r = ((double) rand() / (RAND_MAX));
            if(i%4 == 0){ 
                counterCardNUmber++;
                tmp.setCard(counterCardNUmber,"Heart");
            }
            else if(i%4 == 1){
                 tmp.setCard(counterCardNUmber,"Diamond");
            }
            else if(i%4 == 2){
                tmp.setCard(counterCardNUmber,"Spades");
            }
            else if(i%4 == 3){
                tmp.setCard(counterCardNUmber,"Clubs");
            }

            if(this->player1Cards.size() < 26 && this->player2Cards.size() < 26){
                if(r < 0.5){
                    player1Cards.push_back(tmp);
                }else{
                    player2Cards.push_back(tmp);
                }
            }else{
            if(player1Cards.size() < player2Cards.size()){
                player1Cards.push_back(tmp);
            }else{
                player2Cards.push_back(tmp);
            }
            }
        }
        std::random_shuffle ( player1Cards.begin(), player1Cards.end());
        std::random_shuffle ( player2Cards.begin(), player2Cards.end());
    }
}