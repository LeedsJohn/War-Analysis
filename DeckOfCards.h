// John Leeds
// 3/7/2022
// DeckOfCards.h
// Contains the classes Card, which represents an individual card, and Deck,
// which represents a deck of cards.
#include <string>
#ifndef DECKOFCARDS_HDR
#define DECKOFCARDS_HDR

void setSeed(int seed = -1);
int ranNum(int, int);

class Card{
    public:
        /*
         * default constructor
         * sets myVal to 0, mySuit to ?, and next to nullptr
         */
        Card();

        /*
         * constructor
         * initializes myVal, mySuit, and next to the given values
         */
        Card(int val, char suit, Card* nextCard);

        /*
         * cardString
         * Returns a string with a visual representation of the card
         */
        std::string cardString() const;

        // SETTERS
        void setVal(int val);
        void setSuit(char suit);

        void setNext(Card* newNext);


        // GETTERS
        int getVal() const;
        char getSuit() const;
        Card* getNext() const;

    private:
        int myVal;
        char mySuit;
        Card* next;
};

/* 
 * This class represents a deck of cards.  While most of the functionality
 * is the same as a stack, it also holds the location of the last card
 * to make it easier to insert a card to the bottom of the deck.
 */
class Deck{
    public:
        /*
         * default constructor
         * creates an empty deck of cards
         */
        Deck();

        /*
         * append
         * Adds a deck to the deck
         */
        void append(Deck deck2);

        /*
         * fill
         * Fills the deck of cards with unshuffled cards
         */
        void fill();

        /*
         * print
         * Shows the content of the deck
         */
        void print();

        /*
         * shuffle
         * Shuffles the current deck by repeatedly selecting a random card
         * from the unshuffled cards and swapping it with the next index.
         */
        void shuffle();
       
        /*
         * Swaps the value and suit of two cards
         */
        void swapCardVals(Card* card1, Card* card2);
        /* STACK
         * push
         * Pushes a new card to the top of the deck
         */
        void push(Card* newTop);

        /* STACK
         * pop
         * Removes the top of the deck and returns the card
         */
        Card* pop();

        /* STACK
         * peek
         * Returns the value of the top card without removing it
         */
        Card* peek();

        /*
         * length
         * Returns the number of cards in the deck
         */
        int length() const;

        /*
         * isEmpty
         * Returns true if the length is 0 - else, returns false
         */
        bool isEmpty() const;
        
        /*
         * clear
         * Resets the deck to empty
         */
        void clear();

        // SETTERS
        void setTop(Card* topVal);
        // GETTERS
        Card* getTop() const; // this is the same as peek
        
    private:
        Card* top; // top card
};

#endif
