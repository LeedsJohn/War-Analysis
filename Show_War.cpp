// This program shows a single game of war as a demonstration
#include <iostream>
using namespace std;
#include "War.h"
#include "DeckOfCards.h"

int main(){
    setSeed(1234);
    War game;
    game.playGame(true);
}
