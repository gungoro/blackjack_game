#include "Deck.h"
#include <algorithm>
#include<iostream>

void Deck::populate(){

	clear();  // CLEAR DECK if any elements present
	
	for  (int i=0;i<52;i++){
			
		Card *card = new Card(i);
		push_first(card);		
	}
}

 
void Deck::deal(Hand& hand){

	Card* card = pop_first();
	hand.push_first(card);	

}
		