#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Monster{
private:
  string name;
  int lv;
  int attack;
  int hp;
  int experience;

public:
  Monster();
  Monster(string name, int lv, int attack, int hp, int experience);

  void setName(string name);
  void setLv(int lv);
  void setAttack(int attack);
  void setHp(int hp);
  void setExperience(int experience);

  string getName();
  int getLv();
  int getAttack();
  int getHp();
  int getExperience();
	~Monster();
};
