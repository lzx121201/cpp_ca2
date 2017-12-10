
#pragma once
#include "Item.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Potion : public Item{
private:
  int hp;

public:
  Potion();
  Potion(string name, string description,int hp);

  void setHp(int hp);

  int getHp();
  string toString();

  ~Potion();
};
