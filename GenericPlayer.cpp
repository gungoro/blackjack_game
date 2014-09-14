#include "GenericPlayer.h"
#include <iostream>

bool GenericPlayer::isBusted() const{

	if (getTotal()>21){
		return true;
	}
	else{
		return false;
	}
}

void GenericPlayer::bust() const{

	std::cout<<name<<" busts"<<std::endl;

}

void GenericPlayer::setName(std::string _name) {
	name = _name;
}

std::string GenericPlayer::getName() const{
	return name;

}