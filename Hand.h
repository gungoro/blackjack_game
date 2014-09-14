#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"
#include <ostream>

class Hand{
	
	private:
		std::vector<Card*> cards;

	public:

		Card* pop_first();      // remove card from beginning of hand
		void push_first(Card* card);  // push card to beginning of hand 
		bool isempty();    // check if hand is empty
		
		int number_of_cards();
		
		void shuffle();
		
		void clear();    // clear hand
		int getTotal() const;    // get total value of hand, required for win check
		
		friend std::ostream& operator<<(std::ostream& out, Hand& hand );   // for display

};

#endif