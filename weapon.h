#pragma once
#include "Item.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Weapon : public Item {
private:
  int attack;

public:
  Weapon();
  Weapon(string name, string description,int attack);

  void setAttack(int attack);

  int getAttack();
  string toString();

  ~Weapon();
};
