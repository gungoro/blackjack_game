#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include "Hand.h"
#include <cstring>

class GenericPlayer: public Hand{  // generic player is a hand with additional capabilities
	
	private:
		std::string name;

	public:
		virtual bool isHitting() const = 0;     // check if player is hitting
		bool isBusted() const;   // check if busted
		void bust() const;       // bust
		void setName(std::string);    // set player name
		//friend std::ostream& operator<<(std::ostream& out, GenericPlayer& gp );s
		std::string getName() const;
};

#endif