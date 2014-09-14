
#include "Card.h"

bool Card::isFaceUp() const{

	return faceup;

}

void Card::flip(){

	faceup = faceup^1;
	
}

int Card::getValue() const{

	int value;
	value = static_cast<int>( rank ) + 1; // not recommended in general for enum, but I do it here for simplicity
	value = value < 10 ? value : 10;

	return value;

}

Card::Card(Suit _suit, Rank _rank){
	
	rank = _rank;
	suit = _suit;
	faceup = true;
	
}

Card::Card(int id){

	rank = static_cast<Rank>(id%13);
	suit = static_cast<Suit>(id/13);
	faceup = true;	

}

std::ostream& operator<<(std::ostream& out, Card& card ){

	if (card.isFaceUp() == false){
			out<<" XX ";
		}
	else{
			
		switch(card.suit){
			case heart: out<<"Heart "; break;
			case diamond: out<<"Diamond "; break;
			case club: out<<"Club "; break;
			case spade: out<<"Spade "; break;
		}
		switch(card.rank){
			case ace: out<<"1"; break;
			case two: out<<"2"; break;
			case three: out<<"3"; break;
			case four: out<<"4"; break;
			case five: out<<"5"; break;
			case six: out<<"6"; break;
			case seven: out<<"7"; break;
			case eight: out<<"8"; break;
			case nine: out<<"9"; break;
			case ten: out<<"10"; break;
			case jack: out<<"J"; break;
			case queen: out<<"Q"; break;
			case king: out<<"K"; break;
		}	
	}
	return out;
}

