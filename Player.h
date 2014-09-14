#ifndef PLAYER_H
#define PLAYER_H

#include "GenericPlayer.h"

class Player: public GenericPlayer{
	
	private:
		int chips;   // total player chips 
		int current_bet;   
		

	public:
	    bool isHitting() const;
		void win();      // display win-lose-push-bust, handle chips
		void lose();
		void push() const;
		void bust();
		
		bool isBankrupt();
		
		Player();
		
		void update_bet();  // update and get bet
		int get_bet();
		
		
};

#endif