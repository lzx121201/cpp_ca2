#include "potion.h"


Potion::Potion(){
	hp = 0;
}

Potion::Potion(string n, string d,int h):Item(n,d){
  hp = h;
}

void Potion::setHp(int h){
  hp = h;
}

int Potion::getHp(){
  return hp;
}

string Potion::toString()
{
	return Item::toString() + "\nHP: +" + to_string(hp) + "\n--------------------------------\n";
}

Potion::~Potion(){

}
