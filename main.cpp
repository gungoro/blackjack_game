
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Game.h"

int main(){

	srand (time(NULL));
	
	Game game;
	game.initialize();
	
	while(game.play_round()){
	
	}
}