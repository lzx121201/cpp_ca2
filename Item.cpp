#include "Item.h"


using namespace std;
int Item::item_id = 0;
Item::Item(){
	name = "";
	description ="";
}

Item::Item(string n,string d){
	name=n;
	description=d;
	item_id++;
	id = item_id;
}

void Item::setName(string n){
	name = n ;
}

void Item::setDescription(string d){
	description = d;
}

string Item::getName(){
	return name;
}

string Item::getDescription(){
	return description;
}

string Item::toString()
{
		return  "\nID: " + to_string(id) + "\tName: " + name + "\nDescripton: " + description;
}

Item::~Item(){

}
