# War-Analysis
Analysis of the card game war

Through this project, my goal was to determine the average number of turns that a game of the card game War takes to 
complete. While the game seems simple, the rules are not well defined in terms of what happens when
two players draw the same card and where to place cards that are won. These are the rules that I used to play war:

1) Both players have two card piles - their hand and their discarded cards
2) The players compare their top card. The player with the higher card places both players' cards in their dascrd.
3) If players draw the same value card, a war is initiated - Both players draw a new card to compare if their deck is not empty. From tehre, they attempt to draw 3 more cards, but only draw if both can. If one player runs out, the other player continues to add cards to the pot one by one until a player has won. If they both run out, the war ends and they reshuffle their decks.
4) Once the player's hand is empty, they shuffle their discard pile and that becomes their hand.
5) This process continues until a player runs out of cards.

One might believe that this implementation is flawed because if a player's final card is an Ace, they will most likely
win all of the other player's hand. However, I do not view this as a problem as it's a game of chance.

**After running 10,000 games using this ruleset, I determined that the average length for a game of war is 336 turns.**

This contradicts a frequently cited analysis that concluded that the average length is 262, seen here:

https://www.wimpyprogrammer.com/the-statistics-of-war-the-card-game

This can be explained by his rule for what happens when a war occurs. In his version, if a player runs out of cards,
they instantly lose the war instead of the other player continuing to draw cards. In addition, I believe his
implementantion is flawed because he checks if a player is out of cards one by one. This means that his implementation
is biased towards player 2 because if player 1 runs out of cards, player 2 automatically wins regardless of if they have cards or not. When I implemented a similar rule to my version, my average turns went to 278 turns per game. I believe that the remaining 16 card discrepancy is most likely explained by other subtle differences in our implementations.

![image](https://user-images.githubusercontent.com/94880155/163914811-c33088b4-8aa9-4ca9-9f4b-8b0104334472.png)
