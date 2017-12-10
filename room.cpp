
#include "room.h"

Room::Room(){
	id = 0;
	description = "";
	lvlimit = 0;
	pot;
	w;
	north = 0;
	east = 0;
	south = 0;
	west = 0;

}

Room::Room(int i, string d,int l,Potion p,Weapon weapon,int n,int e,int s,int we,Monster m){
  id = i;
  description = d;
  lvlimit = l;
  pot =p;
  w = weapon;
  north =n;
  east = e;
  south = s;
  west = we;
  monster = m;

}

void Room::setId(int i){
  id = i;
}

void Room::setDescription(string d){
  description = d;
}

void Room::setLvlimit(int l){
  lvlimit = l;
}

void Room::setPot(Potion p){
	pot = p;
}

void Room::setWeapon(Weapon we){
	w = we;
}
void Room::setNorth(int n){
	north = n;
}
void Room::setEast(int e){
	east = e;
}
void Room::setSouth(int s){
	south = s ;
}
void Room::setWest(int we){
	west = we;
}
void Room::setMonster(Monster m){
	monster = m;
}


int Room::getId(){
  return id;
}

string Room::getDescription(){
  return description;
}

int Room::getLvlimit(){
  return lvlimit;
}
Potion Room::getPot(){
	return pot;
}

Weapon Room::getWeapon(){
	return w;
}
int Room::getNorth(){
	return north;
}
int Room::getEast(){
	return east;
}

int Room::getSouth(){
	return south;
}

int Room::getWest(){
	return west;
}
Monster Room::getMonster(){
	return monster;
}

string Room::toString()
{
	string str = "\nRoom: " + to_string(id) + "\nDescription: " + description + "\nEntry: ";
	if( north != -1)
	{
		str += "\n\tNorth: Room " + to_string(north);
	}
	else
	{
		str += "\n\tNorth: \\ " ;
	}

	if( east != -1)
	{
		str += "\n\tEast: Room " + to_string(east);
	}
	else
	{
		str += "\n\tEast: \\ " ;
	}

	if( south != -1)
	{
		str += "\n\tsouth: Room " + to_string(south);
	}
	else
	{
		str += "\n\tsouth: \\ " ;
	}
	if( west != -1)
	{
		str += "\n\tWest: Room " + to_string(west);
	}
	else
	{
		str += "\n\tWest: \\ " ;
	}
	str += "\nWeapon: " + w.getName();
	str += "\nPotion: " + pot.getName();
	str += "\nMonster: " + monster.getName();
	str += "\nLevel Limit: Lv " + to_string(lvlimit);
	str += "\n--------------------------------\n";
	return str;
}

vector<int> Room::getEntry()
{
	vector<int> entry;
	entry.push_back(north);
	entry.push_back(east);
	entry.push_back(south);
	entry.push_back(west);

	return entry;
}

Room::~Room(){

}
