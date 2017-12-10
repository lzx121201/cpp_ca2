#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Item{
	protected:
		static int item_id; // Reference: http://www.bogotobogo.com/cplusplus/statics.php
    int id;
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
