all: test show_war war_analysis

war_analysis: DeckOfCards.o War_Analysis.o War.o
	g++ DeckOfCards.o War_Analysis.o War.o -o war_analysis
show_war: DeckOfCards.o Show_War.o War.o
	g++ DeckOfCards.o Show_War.o War.o -o show_war
test: DeckOfCards.o Test.o
	g++ DeckOfCards.o Test.o -o test

War_Analysis.o: DeckOfCards.o DeckOfCards.h War_Analysis.cpp War.cpp War.h
	g++ -c War_Analysis.cpp -o War_Analysis.o
Show_War.o: DeckOfCards.cpp DeckOfCards.h Show_War.cpp War.cpp War.h
	g++ -c Show_War.cpp -o Show_War.o
War.o: DeckOfCards.cpp DeckOfCards.h War.cpp War.h
	g++ -c War.cpp -o War.o
Test.o: DeckOfCards.cpp DeckOfCards.h Test.cpp
	g++ -c Test.cpp -o Test.o
DeckOfCards.o: DeckOfCards.cpp DeckOfCards.h
	g++ -c DeckOfCards.cpp -o DeckOfCards.o

clean:
	rm *.o test show_war war_analysis
