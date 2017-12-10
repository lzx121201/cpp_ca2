#include "library.h"


int main(void){
								vector<Room> rooms;
								vector<Potion> potions;
								vector<Weapon> weapons;
								vector<Monster> monsters;
								Character c;
								readFile(rooms);
								readItem(potions,weapons);
								readMonster(monsters);
								intro();
								createChar(c);
								inGame(rooms,potions,weapons,monsters,c);
}
