#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "Card.h"
#include "Hand.h"
#include "GenericPlayer.h"
#include "Player.h"
#include "House.h"
#include "Deck.h"

#include <vector>


class Game{
	
	public:
		int initialize();
		int play_round();

	
	private:
		int round_number;
		int player_count;
		
		Deck deck;
		House house;
		std::vector<Player*> player;
		


};

#endif