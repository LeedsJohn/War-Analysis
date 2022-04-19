#include <iostream>
#include <string>
using namespace std;
#include "DeckOfCards.h"

void testCard(){
    cout << "Testing random card: " << endl;
    Card test(1, 'C', nullptr);
    string testCardString = test.cardString();
    cout << testCardString << endl;

    cout << "Setting val to 10 and suit to S" << endl;
    test.setVal(10);
    test.setSuit('S');
    testCardString = test.cardString();
    cout << testCardString << endl;
    
    cout << "Testing getters: 10S" << endl;
    cout << test.getVal() << test.getSuit() << endl;
}

void testDeck(bool printDeck = false){
    Deck test;
    test.fill();
    cout << "Testing Length - should be 52" << endl;
    cout << test.length() << endl;
    if ( printDeck ){
    cout << "PRINTING UNSHUFFLED DECK: " << endl;
    Card* print = test.getTop();
    while ( print ){
        cout << "Beginning of loop before print" << endl;
        cout << print->cardString() << endl;
        print = print->getNext();
    }
    }

    test.shuffle();
    if ( printDeck ){
    cout << "-------------\nPRINTING SHUFFLED DECK: " << endl;
    Card* print = test.getTop();
    while ( print ){
        cout << print->cardString() << endl;
        print = print->getNext();
    }
    }
}

int main(){
    testCard();
    testDeck();
}
