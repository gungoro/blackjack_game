#include "House.h"

bool House::isHitting() const{

	if (getTotal() > 17)
		return false;
	else
		return true;
}


void House::flipFirstCard(){

	Card* card = pop_first();
	card->flip();
	push_first(card);

}

House::House(){
	setName("house");
}