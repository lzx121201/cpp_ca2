
#include "monster.h"


Monster::Monster(){
	name = "";
	lv = 0;
	attack = 0;
	hp = 0;
	experience = 0;
}

Monster::Monster(string n, int l, int a, int h, int e){
  name = n;
  lv = l;
  attack = a;
  hp = h;
  experience = e;
}

void Monster::setName(string n){
  name = n;
}

void Monster::setLv(int l){
  lv = l;
}

void Monster::setAttack(int a){
  attack = a;
}

void Monster::setHp(int h){
  hp = h;
}

void Monster::setExperience(int e){
  experience = e;
}

string Monster::getName(){
  return name;
}

int Monster::getLv(){
  return lv;
}

int Monster::getAttack(){
  return attack;
}

int Monster::getHp(){
  return hp;
}

int Monster::getExperience(){
  return experience;
}

Monster::~Monster(){
	
}