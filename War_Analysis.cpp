// This program performs an analysis to find the average, max, and minimum
// number of turns a game of war can take.  The number will be different from
// results other people found because there is not a standard ruleset for 
// the game of war.
#include <iostream>
using namespace std;
#include "War.h"
#include "DeckOfCards.h"

int main(){
    int trials = 10000;
    setSeed(442002);
    War game;
    int sum = 0;
    int min;
    int max;
    for ( int i = 0; i<trials; i++ ){
        int moves = game.playGame(false);
        sum += moves;
        if ( moves < min ) min = moves; 
        if ( moves > max ) max = moves;
    }
    cout << " NUM TRIALS: " << trials << endl;
    cout << "TOTAL TURNS: " << sum << endl;
    cout << " AVG  TURNS: " << sum/trials << endl;
    cout << " MIN  TURNS: " << min << endl;
    cout << " MAX  TURNS: " << max << endl;
}
