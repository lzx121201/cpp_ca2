
#include "weapon.h"

Weapon::Weapon(){
	attack = 0;
}

Weapon::Weapon(string n, string d,int a):Item(n,d){
  attack = a;
}

void Weapon::setAttack(int a){
  attack = a;
}

int Weapon::getAttack(){
  return attack;
}

string Weapon::toString()
{
	return Item::toString() + "\nAttack: +" + to_string(attack) + "\n--------------------------------\n";
}

 Weapon::~Weapon(){

 }
