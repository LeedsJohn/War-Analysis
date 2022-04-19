// War.cpp
// John Leeds
// 3/7/2022
// Simulates a game of the card game war
#include <iostream>
using namespace std;
#include "War.h"
#include "DeckOfCards.h"

/* 
 * Default constructor
 * Gives both players 26 random cards
 */
War::War(){
    Deck deal;
    deal.fill();
    deal.shuffle();
    for ( int i = 0; i<26; i++ ){
        Card* card1 = deal.pop();
        Card* card2 = deal.pop();
        p1.push(card1);
        p2.push(card2);
    }
}

/*
 * reset
 * Gives both players 26 random cards
 */
void War::reset(){
    p1.clear();
    p2.clear();
    p1Wins.clear();
    p2Wins.clear();
    Deck deck;
    deck.fill();
    deck.shuffle();
    for ( int i = 0; i<26; i++ ){
        Card* card1 = deck.pop();
        Card* card2 = deck.pop();
        p1.push(card1);
        p2.push(card2);
    }
}

/*
 * compare
 * Provides two cards, card1 and card2. Returns 1 if card1 > card2,
 * Returns 2 if card2 > card1, Returns 0 if card1 == card2
 * If no parameters are provided, the top card from each deck is taken
 */
int War::compare(Card* card1 = nullptr, Card* card2 = nullptr){
    if ( card1 == nullptr){
    Card* card1 = p1.peek();
    Card* card2 = p2.peek();
    if ( card1->getVal() == 1 && card2->getVal() != 1 ) return 1; // aces
    if ( card2->getVal() == 1 && card1->getVal() != 1 ) return 2;
    if ( card1->getVal() > card2->getVal() ) return 1;
    if ( card2->getVal() > card1->getVal() ) return 2;
    return 0;
    }
    if ( card1->getVal() == 1 && card2->getVal() != 1 ) return 1;
    if ( card2->getVal() == 1 && card1->getVal() != 1 ) return 2;
    if ( card1->getVal() > card2->getVal() ) return 1;
    if ( card2->getVal() > card1->getVal() ) return 2;
    return 0;
}

/*
 * simulateWar
 * If two players draw cards with equal values, they enter a war
 * They each attempt to put down 3 blank cards followed by their
 * "war card," which are then judged against each other.
 * Each player begins by drawing a card if possible and then
 * attempt to draw 3 more, but neither can draw more than the other
 * If both players run out of cards and their last cards are equal,
 * they reshuffle their decks
 * If a tie occurs again, this function calls itself recursively
 * parameters:
 * p - whether to print or not
 * warCard1/warCard2 - the two players war cards
 * numCards1/numCards2 - the number of cards that the player has wagered 
 */
void War::simulateWar(bool p, Card* warCard1, Card* warCard2, int numCards1, int numCards2){
    Card blank(0, 'X', nullptr);
    string blankCard = blank.cardString();

    if ( p && numCards1 == 1 && numCards2 == 1 ){
        cout << "Entering a WAR!!!" << endl;
    }

    if ( warCard1->getNext() != nullptr ){
        warCard1 = warCard1->getNext();
        numCards1++;
    }
    if ( warCard2->getNext() != nullptr ){
        warCard2 = warCard2->getNext();
        numCards2++;
    }
    for ( int i = 0; i<3; i++ ){
        if ( warCard1->getNext() != nullptr && warCard2->getNext() != nullptr ){
            warCard1 = warCard1->getNext();
            warCard2 = warCard2->getNext();
            numCards1++;
            numCards2++;
            if (p){
                cout << "Player 1 places down a blank card:\n" << blankCard << endl;
                cout << "Player 2 places down a blank card:\n" << blankCard << endl;
            }
        }
        else break;
    }
    if (p){
        cout << "Player 1 war card:\n" << warCard1->cardString() << endl;
        cout << "Player 2 war card:\n" << warCard2->cardString() << endl;
    }
    
    int maxCards;
    if ( numCards1 > numCards2 ) maxCards = numCards1;
    else maxCards = numCards2;
    int winner = compare(warCard1, warCard2);
    if ( winner == 1 ){
        if (p) cout << "Player 1 wins " << numCards2 << " cards from Player 2." << endl;
        putCards(maxCards, 1);
        return;
    }
    if ( winner == 2 ){
        if (p) cout << "Player 2 wins " << numCards1 << " cards from Player 1." << endl;
        putCards(maxCards, 2);
        return;
    }

    if ( warCard1->getNext() == nullptr && warCard2->getNext() == nullptr ){
        if (p) cout << "There was a tie - reshuffle" << endl;
        if ( p1Wins.isEmpty() ){
            p1Wins.setTop(p1.getTop());
            p1.setTop(NULL);
        }
        else{
            p1Wins.append(p1);
            p1.setTop(NULL);
        }
        if ( p2Wins.isEmpty() ){
            p2Wins.setTop(p2.getTop());
            p2.setTop(NULL);
        }
        else{
            p2Wins.append(p2);
            p2.setTop(NULL);
        }
        p1.clear();
        p2.clear();
        return;
    }
    simulateWar(p, warCard1, warCard2, numCards1, numCards2);
}


/*
 * putCards
 * Inserts a specified number of cards from each player
 * to the back of a specified player's deck
 */
void War::putCards(int num, int p){
    for ( int i = 0; i<num; i++ ){
        Card* card1;
        Card* card2;
        if ( p1.isEmpty() == false){
            card1 = p1.pop();
        }
        else{
            card1 = NULL;
        }
        if ( p2.isEmpty() == false){
            card2 = p2.pop();
        }
        else{
            card2 = NULL;
        }


        if ( p == 1 ){
            p1Wins.push(card1);
            p1Wins.push(card2);
        }
        else{
            p2Wins.push(card1);
            p2Wins.push(card2);
        }
    }
}

/*
 * playGame
 * Plays a game of war
 * Players maintain their hand and a discard pile - once their hand empties,
 * they shuffle their discard pile and that becomes their hand.
 * They put cards that they played / won in the discard pile.
 * If p is true, the status of the game will be printed.
 */
int War::playGame( bool p ){
    reset();
    if(p) cout << "Welcome to war. Good luck." << endl;
    int turn = 0;
    while ( p1.isEmpty() == false && p2.isEmpty() == false){
        turn++;
        if(p) cout << "-----------------" << endl;
        if(p) cout << "Turn " << turn << endl;

        if(p) cout << "Player 1's Card: \n" << p1.getTop()->cardString() << endl;
        if(p) cout << "Player 2's Card: \n" << p2.getTop()->cardString() << endl;
        int winner = compare();
        if ( winner == 1 ){
            if(p) cout << "Player 1 wins!" << endl;
            putCards(1, 1);
        }
        else if ( winner == 2 ){
            if(p) cout << "Player 2 wins!" << endl;
            putCards(1, 2);
        }
        else{
            simulateWar(p, p1.peek(), p2.peek(), 1, 1);
        }
        
        if ( p1.isEmpty() && p1Wins.isEmpty() == false ){
            if(p) cout << "Reshuffling player 1." << endl;
            p1.setTop(p1Wins.getTop());
            p1Wins.clear();
            p1.shuffle();
        }
        if ( p2.isEmpty() && p2Wins.isEmpty() == false ){
            if(p) cout << "Reshuffling player 2." << endl;
            p2.setTop(p2Wins.getTop());
            p2Wins.clear();
            p2.shuffle();
        }
        
        if(p) cout << "Cards after turn " << turn << ": " << endl;
        if(p) cout << "Player 1: " << p1.length() + p1Wins.length() << 
                " (" << p1.length() << " in hand, " << p1Wins.length() << 
                " discarded)" << endl;
        if(p) cout << "Player 2: " << p2.length() + p2Wins.length() <<
                " (" << p2.length() << " in hand, " << p2Wins.length () <<
                " discarded)" << endl;
    }
    if(p) cout << "---------------------" << endl;
    if ( p2.isEmpty() ){
        if(p) cout << "PLAYER 1 WINS!!! good job." << endl;
    }
    else if ( p1.isEmpty() ){
        if(p) cout << "PLAYER 2 WINS!!! good job." << endl;
    }
    return turn;
}
