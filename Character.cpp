#include "Character.h"
#include <iostream>
#include <unistd.h>

using namespace std;

Character::Character(){
	name="";
	job="";
	skill= "";
	lv =0;
	currenthp = 0;
	maxhp;
	attack = 0 ;
	weapons;
	potions;
	currentexp =0;
	maxexp;
	w;
	currentLocation = 1;
}

Character::Character(string n,string j,string s,int level,int ch,vector<int> m,int a,vector<Potion> ps,vector<Weapon> ws,int ce,vector<int> me,Weapon we,int cl){
	name=n;
	job=j;
	skill=s;
	lv =level;
	currenthp = ch ;
	maxhp = m;
	attack = a ;
	potions = ps ;
	weapons = ws;
	currentexp = ce;
	maxexp = me;
	w = we;
	currentLocation  = cl;
}

void Character::setName(string n){
	name = n ;
}
void Character::setJob(string j){
	job = j ;
}
void Character::setSkill(string s){
	skill = s ;
}
void Character::setLv(int level){
	lv = level ;
}
void Character::setCurrenthp(int ch){
	currenthp = ch;
}
void Character::setMaxhp(vector<int> m){
	maxhp = m ;
}
void Character::setAttack(int a){
	attack = a;
}
void Character::setWeapons(vector<Weapon> ws){
	weapons = ws;
}
void Character::setPotions(vector<Potion> ps){
	potions = ps;
}
void Character::setCurrentexp(int ce){
	currentexp = ce;
}
void Character::setMaxexp(vector<int> me){
	maxexp = me;
}
void Character::setWeapon(Weapon we){
	w=we ;
}

void Character::setCurrentLocation(int cl)
{
	currentLocation = cl;
}

string Character::getName(){
	return name;
}
string Character::getJon(){
	return job;
}
string Character::getSkill(){
	return skill;
}
int Character::getLv(){
	return lv;
}
int Character::getCurrenthp(){
	return currenthp;
}
vector<int> Character::getMaxhp(){
	return maxhp;
}
int Character::getAttack(){
	return attack;
}
vector<Weapon> Character::getWeapons(){
	return weapons;
}
vector<Potion> Character::getPotions(){
	return potions;
}
int Character::getCurrentexp(){
	return currentexp;
}
vector<int> Character::getMaxexp(){
	return maxexp;
}
Weapon Character::getWeapon(){
	return w;
}

int Character::getCurrentLocation()
{
	return currentLocation;
}

void Character::displayInventory()
{
	for (Weapon w : weapons)
	{
		cout << w.toString() << endl;
	}
	for (Potion p : potions)
	{
		cout << p.toString() <<  endl;
	}

}

void Character::printCurrentLoaction(vector<Room> &rooms)
{
	Room r = rooms[currentLocation-1];
	cout << r.toString() << endl;
}

void Character::move(vector<Room> &rooms,int roomID)
{
	Room r = rooms[currentLocation-1];
	vector<int> entry = r.getEntry();
	bool moved = false;
	int i  = 0;
	while(moved == false && i < entry.size())
	{
		if(roomID == entry[i])
		{
			int lvlim = rooms[roomID].getLvlimit();
			if(lv >= lvlim)
			{
				currentLocation = roomID;
			}
			else
			{
				cout << "That room requires character Lv " << to_string(lvlim) << " You're current Lv " << to_string(lv) << endl;
			}
		}
		else
		{
			cout << "No such entry point in this room." << endl;
		}
	}
}

void Character::addExp(int exp)
{
	if(lv < 10)
	{
		int currentMaxExp = maxexp[lv-1];
		currentexp  += exp;
		if(currentexp >= currentMaxExp)
		{
			lv += 1;
			currenthp = maxhp[lv-1];
			cout << " Congratulations! You reached Lv " << to_string(lv) << endl;
		}
	}
	else
	{
		cout << "Congratulation! You reached the top level!" << endl;
	}
}

void Character::fightMonster(Monster &m)
{
	cout << "Battle start!" << endl;
	int m_hp = m.getHp();
	int m_attack = m.getAttack();
	string m_name = m.getName();
	bool got_result = false;
	bool won = false;
	int i = 1;
	while(got_result)
	{
		if(i % 2 != 0)
		{
			m_hp -= attack;
			cout << "You attacked " << m_name << ". Your current HP: " << to_string(currenthp) << "   " << m_name << "'s current HP: " << to_string(m_hp) << endl;
		}
		else
		{
			currenthp -= m_attack;
			cout << "You are attacked by " << m_name << ". Your current HP: " << to_string(currenthp) << "   " << m_name << "'s current HP: " << to_string(m_hp) << endl;
		}

		if(m_hp <= 0)
		{
			got_result = true;
			won = true;
		}
		if(currenthp <= 0)
		{
			got_result = true;
		}

		if(won == true )
		{
			int m_exp = m.getExperience();
			addExp(m_exp);
		}
		else
		{
			cout << "Unfortunately, you were defeated and you'll be reborn in the village soon." << endl;
			usleep(10000);
			currentLocation = 1;
			currenthp = maxhp[lv-1];
		}
	}
}

void Character::pickupItem(Potion &p)
{
	if(potions.size() == 0)
	{
		potions.push_back(p);
		potion_quantity.push_back(1);
	}
	else
	{
		int i = 0;
		int pos = -1;
		while(i < potions.size() && pos == -1)
		{
			if(potions[i].getName() == p.getName())
			{
				pos = i;
			}
			i++;
		}
		if(pos ==  -1)
		{
			potions.push_back(p);
			potion_quantity.push_back(1);
		}
		else
		{
			potion_quantity[i] += 1;
		}
	}
	cout << "Item added!" << endl;
}

void Character::pickupItem(Weapon &w)
{
	if(weapons.size() ==0)
	{
		weapons.push_back(w);
	}
	else
	{
		int i = 0;
		int pos = -1;
		while(i < weapons.size() && pos == -1)
		{
			if(weapons[i].getName() == w.getName())
			{
				pos = i;
			}
			i++;
		}
		if(pos ==  -1)
		{
			weapons.push_back(w);
		}
		else
		{
			cout << "You've already have the weapon." << endl;
		}
	}
}

void Character::equipWeapon(int i)
{
	int w_attack = weapons[i].getAttack();
	attack += w_attack;
	cout << "Your attack are now " << to_string(attack) << endl;

}
void Character::usePotion(int i)
{
	Potion p = potions[i];
	int p_hp = p.getHp();
	if(currenthp >= maxhp[lv-1])
	{
		cout << "You don't need any potion for now." << endl;
	}
	else
	{
		currenthp += p_hp;
		if(currenthp >= maxhp[lv-1])
		{
			currenthp = maxhp[lv-1];
		}
		cout << "Your current HP: " << to_string(currenthp) << endl;

	}
}
void Character::addItem(){

}

void Character::removeItem(){

}

Character::~Character(){

}
