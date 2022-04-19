// John Leeds
// 3/7/2022
// DeckOfCards.cpp
// Implementation of Card and Deck
#include <iostream>
#include <string>
#include <stdlib.h> // for random number generation
#include <time.h> // get time to set seed for random number gen
using namespace std;
#include "DeckOfCards.h"

void setSeed(int seed /*=-1*/ ){
    if ( seed != -1 ) srand(seed);
    else
        srand(time(NULL));
}
/*
 * ranNum
 * Preconditions:
 * Receives a minimum and maximum value (inclusive)
 * defaults to 0-3
 * Returns:
 * A pseudo-random number between min and max (inclusive)
 */
int ranNum(int min, int max){
    return rand()%(max-min+1) + min;
}

/*
 * default constructor
 * sets myVal to 0, mySuit to ?, and next to nullptr
 */
Card::Card(){
    myVal = 0;
    mySuit = '?';
    next = nullptr;
}

/*
 * constructor
 * initializes myVal, mySuit, and next to the given values
 */
Card::Card(int val, char suit, Card* nextCard){
    myVal = val;
    mySuit = suit;
    next = nextCard;
}

/*
 * cardString
 * Returns a string with a visual representation of the card
 */
string Card::cardString() const{
    string card = " _______ \n|";
    string val;
    if ( (myVal > 1 && myVal < 11) ){
        val = to_string(myVal);
    }
    else if ( myVal == 0 ){
        val = "?";
    }
    else if ( myVal == 1 ) val = "A"; // TODO: make this into a function?
    else if ( myVal == 11 ) val = "J";
    else if ( myVal == 12 ) val = "Q";
    else if ( myVal == 13 ) val = 'K';
    card.append(val);
    if ( myVal != 10 ) card.append("      |\n|       |\n|   ");
    else card.append("     |\n|       |\n|   ");
    string suit;
    if ( mySuit == 'S' ) suit = "♠";
    else if ( mySuit == 'H' ) suit = "♥";
    else if ( mySuit == 'D' ) suit = "♦";
    else if ( mySuit == 'C' ) suit = "♣";
    else suit = "X"; // protection
    card.append(suit);
    string temp;
    if ( myVal != 10 ) temp = "   |\n|       |\n|      ";
    else temp = "   |\n|       |\n|     ";
    card.append(temp);
    card.append(val);
    temp = "|\n ‾‾‾‾‾‾‾ ";
    card.append(temp);
    return card;
}

// SETTERS
void Card::setVal(int val){
    myVal = val;
}
void Card::setSuit(char suit){
    mySuit = suit;
}
void Card::setNext(Card* newNext){
    next = newNext;
}
// GETTERS
int Card::getVal() const{
    return myVal;
}
char Card::getSuit() const{
    return mySuit;
}
Card* Card::getNext() const{
    return next;
}

/* 
 * This class represents a deck of cards.  While most of the functionality
 * is the same as a stack, it also holds the location of the last card
 * to make it easier to insert a card to the bottom of the deck.
 */
/*
 * default constructor
 * Creates a deck of cards in a predetermined order
 */
Deck::Deck(){
    top = NULL;
}

/*
 * fill
 * Fills the deck of cards with unshuffled cards
 */
void Deck::fill(){
    for ( int val = 13; val>0; val-- ){ // generate from top to bottom
        char suits[4] = {'C', 'D', 'H', 'S'};
        for ( int suit = 0; suit<4; suit++ ){
            Card* newCard = new Card(val, suits[suit], nullptr);
            push(newCard);
        }
    }
}

/*
 * append
 * Adds a deck to the deck
 */
void Deck::append(Deck deck2){
    Card* findBack = top;
    while ( findBack->getNext() ){
        findBack = findBack->getNext();
    }
    findBack->setNext(deck2.peek());
}

/*
 * print
 * Shows the content of the deck
 */
void Deck::print(){
    Card* print = top;
    while ( print ){
        cout << print->getVal() << print->getSuit() << ' ';
        print = print->getNext();
    }
    cout << endl;
}

/*
 * shuffle
 * Shuffles the current deck by repeatedly selecting a random card
 * from the unshuffled cards and swapping it with the next index.
 */
void Deck::shuffle(){
    int l = length();
    Card* curCard = top;
    for ( int i = 0; i<l-1; i++ ){
        Card* swapCard = curCard;
        int ahead = ranNum(0, l-i-1); // TODO: should this be l-i-1?
        for ( int i2 = 0; i2<ahead; i2++ ){
            swapCard = swapCard->getNext();
        }
        swapCardVals(curCard, swapCard);
        curCard = curCard->getNext();
    }
}

/*
 * swapCardVals
 * Swaps the value and suit of two cards
 */
void Deck::swapCardVals(Card* card1, Card* card2){
    int swapVal = card1->getVal();
    char swapSuit = card1->getSuit();

    card1->setVal(card2->getVal());
    card1->setSuit(card2->getSuit());
    card2->setVal(swapVal);
    card2->setSuit(swapSuit);
}

/* STACK
 * push
 * Pushes a new card to the top of the deck
 */
void Deck::push(Card* newTop){
    if ( newTop == NULL ) return;
    newTop->setNext(top);
    top = newTop;
}

/* STACK
 * pop
 * Removes the top of the deck and returns the card
 */
Card* Deck::pop(){
    Card* oldTop = top;
    top = top->getNext();
    return oldTop;
}

/* STACK
 * peek
 * Returns the top card without removing it
 */
Card* Deck::peek(){
    return top;
}

/*
 * length
 * Returns the number of cards in the deck
 */
int Deck::length() const{
    if ( isEmpty() ){
        return 0;
    }
    Card* count = top;
    int c = 0;
    while ( count != NULL ){
        c++;
//        cout << count->getVal() << count->getSuit() << endl;
        count = count->getNext();
    }
    return c;
}

/*
 * isEmpty
 * Returns true if the length is 0 - else, returns false
 */
bool Deck::isEmpty() const{
    if ( top == NULL ) return true;
    return false;
}

/*
 * clear
 * Resets the deck to empty
 */
void Deck::clear(){
    top = NULL;
}

// SETTERS
void Deck::setTop(Card* topVal){
    top = topVal;
}

// GETTERS
Card* Deck::getTop() const{ // this is the same as peek
    return top;
}
