#ifndef HOUSE_H
#define HOUSE_H

#include "GenericPlayer.h"

class House: public GenericPlayer{
	
	private:
		

	public:
		virtual bool isHitting() const;
		void flipFirstCard();
		House();
};

#endif