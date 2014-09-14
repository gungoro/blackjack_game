#ifndef DECK_H
#define DECK_H

#include "Hand.h"
#include "GenericPlayer.h"

class Deck: public Hand{
	
	private:
		

	public:
		void populate();   // generate a deck of 52 cards
		//void shuffle();    // shuffle the deck 
		void deal(Hand& hand);  // deal a card to a hand
		// void additionalCards(GenericPlayer& gp);
};

#endif