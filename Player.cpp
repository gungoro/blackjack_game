#include "Player.h"

#include <iostream>


bool Player::isHitting() const{

	char want_a_hit;
	std::cout<<getName()<<". Do you want to hit?: y/n"<<std::endl;
	std::cin>>want_a_hit;
	
	if (want_a_hit == 'y')
		return true;
	else
		return false;
		
}

void Player::win(){

	std::cout<<getName()<<" wins"<<std::endl;
	chips += current_bet;

}

void Player::lose(){

	std::cout<<getName()<<" loses"<<std::endl;
	chips -= current_bet;
	
}

bool Player::isBankrupt(){
	
	return (chips < 1);

}


void Player::push() const{

	std::cout<<getName()<<" pushes"<<std::endl;

}

void Player::bust(){
	

	std::cout<<getName()<<" busts"<<std::endl;
	chips -= current_bet;
}



Player::Player(){
	chips = 100;
}

void Player::update_bet(){
	int new_bet;
	
	do {
		std::cout<<getName()<<" : You have "<<chips<<" chips. Please enter bet (minimum 1 chip): "<<std::endl;
		std::cin>>new_bet;
	} while (new_bet > chips || new_bet < 1);
	
	current_bet = new_bet;
	
}

int Player::get_bet(){
	return current_bet;
}

