#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Item{
	private:
  	string name;
	string description;

	public:
		Item();
		Item(string name,string Description);

		void setName(string name);
		void setDescription(string description);

		string getName();
		string getDescription();
		string toString();


		~Item();

};
