#include "Hand.h"
#include <algorithm>
#include <cstdlib>


int Hand::number_of_cards(){

	return cards.size();

}


bool Hand::isempty(){

	return cards.empty();

}


void Hand::clear(){

	while(!cards.empty()) delete cards.back(), cards.pop_back();
}

int Hand::getTotal() const{  // returns total value in hand

	int total = 0, aces = 0, card_val;  // also handle the aces: can count for either 1 or 11
	for (unsigned int i =0; i< cards.size();i++){
		card_val = cards[i]->getValue();
		if (card_val == 1){
			aces ++;
		}
		total += card_val;
	}	
	for (int i=0; i< aces; i++){
		if (total < 11){
			total = total + 10;
		}
	}
	return total;
}

Card* Hand::pop_first(){  // pop first card from the hand and returns it

	Card* removed_card = cards[0];
	cards.erase(cards.begin());
	
	return removed_card;
}

void Hand::push_first(Card* inserted_card){  // push the card to the beginning of hand

	cards.insert(cards.begin(), inserted_card);

}

void Hand::shuffle(){

	std::random_shuffle ( cards.begin(), cards.end() );

}


std::ostream& operator<<(std::ostream& out, Hand& hand ) {  // output to ostream
	for(unsigned i = 0; i < hand.cards.size(); i++){
		out<<*(hand.cards[i])<<" ";
	}
	return out;
}
