#pragma once
#include "weapon.h"
#include "potion.h"
#include "room.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Character {
private:
string name;
string job;
string skill;
int lv;
int currenthp;
vector<int> maxhp;
int attack;
vector<Potion> potions;
vector<int> potion_quantity;
vector<Weapon> weapons;
int currentexp;
vector<int> maxexp;
Weapon w;
int currentLocation;

public:

Character();

Character(string name,string job,string skill,int lv,int currenthp,vector<int> maxhp,int attack,vector<Potion> potions,vector<Weapon> weapons,int currentexp,vector<int> maxexp,Weapon w,int cl);

void setName(string name);
void setJob(string job);
void setSkill(string skill);
void setLv(int lv);
void setCurrenthp(int currenthp);
void setMaxhp(vector<int> maxhp);
void setAttack(int attack);
void setWeapons(vector<Weapon> weapons);
void setPotions(vector<Potion> potions);
void setCurrentexp(int currentexp);
void setMaxexp(vector<int> maxexp);
void setWeapon(Weapon w);
void setCurrentLocation(int cl);

string getName();
string getJon();
string getSkill();
int getLv();
int getCurrenthp();
vector<int> getMaxhp();
int getAttack();
vector<Weapon> getWeapons();
vector<Potion> getPotions();
int getCurrentexp();
vector<int> getMaxexp();
Weapon getWeapon();
int getCurrentLocation();

void addExp(int exp);
void displayInventory();
void printCurrentLoaction(vector<Room> &rooms);
void move(vector<Room> &rooms, int roomID);
void fightMonster(Monster &m);
void pickupItem(Potion &p);
void pickupItem(Weapon &w);
void equipWeapon(int i);
void usePotion(int i);



~Character();
};
