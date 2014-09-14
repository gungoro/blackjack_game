#include "Game.h"

int Game::initialize(){   // returns 1 if there is an error

	std::cout<<"Please enter the number of players"<<std::endl;
	std::cin>>player_count;	
	if (player_count < 1 || player_count > 7){
		std::cerr<<"Invalid player count\n";
		return 1;
	}	
	
	for (int i=0 ; i<player_count; i++){
		std::string player_name;
		std::cout<<"Please enter the name of player "<<i+1<<std::endl;
	    std::cin>>player_name;
		
		Player* newplayer = new Player();
		newplayer->setName(player_name);
		player.push_back(newplayer);
	}

	round_number = 0;
		
	return 0;
}

int Game::play_round(){


	round_number ++;
	std::cout<<"Round  "<<round_number<<":"<<std::endl;
	

	if(deck.number_of_cards() < 4 * (player_count+1)){
		deck.populate();
		deck.shuffle();   // deal and shuffle cards
		std::cout<<"Deck populated. .."<<std::endl;
	}
	
	

	for (int i=0; i<player_count; i++){   // update_bet of players, deal cards
		player[i]->update_bet();
		deck.deal(*player[i]);
		deck.deal(*player[i]);
	}
	deck.deal(house);
	deck.deal(house);	// deal two cards each to player and house
	
	house.flipFirstCard(); // hide the first card of the house
	
	for (int i=0; i<player_count; i++){    // display cards of house and player IMPLEMENT A DISPLAY method
		std::cout<<player[i]->getName()<<" "<<*player[i]<<std::endl;
	}
	std::cout<<house.getName()<<" "<<house<<std::endl;
	
	for (int i=0; i<player_count; i++){     // check if players are busted. If not, query them for hit/stand
		while (player[i]->isHitting() == true){
			deck.deal(*player[i]);
			std::cout<<player[i]->getName()<<" "<<*player[i]<<std::endl;
			if (player[i]->isBusted()== true){
				player[i]->bust();
				break;
			}
		}
	}

	house.flipFirstCard(); // reveal the first card of the house
	while (house.isHitting() == true){
		deck.deal(house);
		if (house.isBusted()== true){
				// house.bust();
				break;
		}
	}
	std::cout<<house.getName()<<" "<<house<<std::endl;   // display all cards of house
	
	if (house.isBusted() == true){    // check if players win/ lose / bust/ push
		for (int i=0; i<player_count; i++)
			if (player[i]->isBusted() == false)
				player[i]->win();
	}
	else {
		for (int i=0; i<player_count; i++){
			if (player[i]->isBusted()==false){
				if (player[i]->getTotal() > house.getTotal()){
					player[i]->win();
				}
				else if  (player[i]->getTotal() < house.getTotal()){
					player[i]->lose();
					if (player[i]->isBankrupt() == true){
						std::cout<<player[i]->getName()<<" goes bankrupt and leaves the game .."<<std::endl; 
						delete player[i];
						
						player_count --;
					}
				}
				else{
					player[i]->push();
				}
			}
		}
	}
	
	for (int i=0; i<player_count; i++){  // end round. clear cards of players
		player[i]->clear();
	}
	house.clear();
	
	return player_count;

}