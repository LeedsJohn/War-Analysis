// War.h
// John Leeds
// 3/7/2022
// Simulates a game of the card game war
#include "DeckOfCards.h"

class War{
    public:
        /* 
         * Default constructor
         * Gives both players 26 random cards
         */
        War();
        
        /*
         * reset
         * Gives both players 26 random cards
         */
        void reset();

        /*

        * compare
        * Provides two cards, card1 and card2. Returns 1 if card1 > card2,
        * Returns 2 if card2 > card1, Returns 0 if card1 == card2
        * If no parameters are provided, the top card from each deck is taken
        */
        int compare(Card* card1, Card* card2);

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
        void simulateWar(bool p, Card* warCard1, Card* warCard2, int numCards1, int numCards2);
        
        /*
         * putCards
         * Inserts a specified number of cards from each player
         * to the back of a specified player's deck
         */
        void putCards(int num, int p);

        /*
         * playGame
         * Plays a game of war
         * Players maintain their hand and a discard pile - once their hand empties,
         * they shuffle their discard pile and that becomes their hand.
         * They put cards that they played / won in the discard pile.
         * If p is true, the status of the game will be printed.
         */
        int playGame(bool p);

    private:
        Deck p1;
        Deck p1Wins;
        Deck p2;
        Deck p2Wins;
};
