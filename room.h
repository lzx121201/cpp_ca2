#pragma once
#include "monster.h"
#include "potion.h"
#include "weapon.h"

using namespace std;

class Room{
private:
  int id;
  string description;
  int lvlimit;
  Potion pot;
  Weapon w;
  int north;
  int east;
  int south;
  int west;
  Monster monster;

public:
  Room();
  Room(int id,string description,int lvlimit,Potion pot,Weapon w,int north, int east,int south,int west,Monster monster);

  void setId(int id);
  void setDescription(string description);
  void setLvlimit(int lvlimit);
  void setPot(Potion pot);
  void setWeapon(Weapon w);
  void setNorth(int n);
  void setEast(int e);
  void setSouth(int s);
  void setWest(int west);
  void setMonster(Monster m);

  int getId();
  string getDescription();
  int getLvlimit();
  vector<Item> getDrops();
  Potion getPot();
  Weapon getWeapon();
  Monster getMonster();
  vector<int> getEntry();

  int getNorth();
  int getEast();
  int getSouth();
  int getWest();


  Item addItem();
  Item removeItem();

  string toString();

  ~Room();
};
