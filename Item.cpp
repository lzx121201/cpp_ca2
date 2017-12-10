#include "Item.h"


using namespace std;

Item::Item(){
	name = "";
	description ="";
}

Item::Item(string n,string d){
	name=n;
	description=d;
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
		return "\nName: " + name + "\nDescripton: " + description;
}

Item::~Item(){

}
