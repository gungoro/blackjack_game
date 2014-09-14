#ifndef CARD_H
#define CARD_H

#include <ostream>

enum Suit {heart, diamond, club, spade};
enum Rank {ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king}; 


class Card{
	
	public:
	
	
	bool isFaceUp() const;    //check if card is face up
	int getValue() const;     // get value of card
	void flip();             
	
	Card(Suit, Rank);
	Card(int);
	friend std::ostream& operator<<(std::ostream& out, Card& card );
	
	private:
	    bool faceup;
		Suit suit;
		Rank rank;	

};

#endif