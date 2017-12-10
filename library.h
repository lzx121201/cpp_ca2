#pragma once
#include "room.h"
#include "Character.h"
#include <vector>
#include <sstream>
#include <string>
#include <unistd.h>

using namespace std;

void readFile(vector<Room> &rooms){
        ifstream inputFile("rooms.txt");
        if(!inputFile) {
                cerr<<"File not found"<<endl;
        }
        if(inputFile.is_open()) {
                while(!inputFile.eof()) {

                        Room r;
                        string t;
                        getline(inputFile,t);
                        if(t.find("Room: ")!=string::npos) {
                                r.setId(stoi(t.substr(t.find(":")+2)));
                                bool exit = false;
                                while(!exit) {
                                        string p;
                                        getline(inputFile,p);
                                        if(p.find("Description: ") != string::npos) {
                                                r.setDescription(p.substr(p.find(":")+2));
                                        }else if(p.find("Direction: ")!=string::npos) {
                                                string temp = p.substr(p.find(":")+2);
                                                stringstream stream(temp);
                                                vector<int> values;
                                                int n;
                                                while(stream>>n) {
                                                        values.push_back(n);
                                                }
                                                r.setNorth(values[0]);
                                                r.setEast(values[1]);
                                                r.setSouth(values[2]);
                                                r.setWest(values[3]);

                                        }else if(p.find("Weapon: ")  !=string::npos) {
                                                Weapon w(p.substr(p.find(":")+2),"",0);
                                                r.setWeapon(w);
                                        }else if(p.find("Potion: ") !=string::npos) {
                                                Potion pot(p.substr(p.find(":")+2),"",0);
                                                r.setPot(pot);
                                        }else if(p.find("Monster: ") !=string::npos) {
                                                Monster m(p.substr(p.find(":")+2),0,0,0,0);
                                                r.setMonster(m);
                                        }else if(p.find("Level Limit: ") !=string::npos) {
                                                r.setLvlimit(stoi(p.substr(p.find(":")+2)));
                                        }else{
                                                exit = true;
                                                rooms.push_back(r);
                                        }
                                }
                        }
                }
                inputFile.close();
        }
}

void readItem(vector<Potion> &potions,vector<Weapon> &weapons){
        ifstream inputFile("item.txt");
        if(!inputFile) {
                cerr<<"File not found"<<endl;
        }
        if(inputFile.is_open()) {
                while(!inputFile.eof()) {
                        string t;
                        string temp;
                        getline(inputFile,t);
                        if(t.find("Type: ") !=string::npos) {
                                temp = t.substr(t.find(":")+2);
                                if (temp == "weapon") {
                                        Weapon w;
                                        string s;
                                        bool exit = false;
                                        while(!exit) {
                                                getline(inputFile,s);
                                                if(s.find("Name: ") != string::npos) {
                                                        w.setName(s.substr(s.find(":")+2));
                                                }else if(s.find("Description: ")!=string::npos) {
                                                        w.setDescription(s.substr(s.find(":")+2));
                                                }else if(s.find("Function: ")!=string::npos) {
                                                        w.setAttack(stoi(s.substr(s.find(":")+2)));
                                                }else{
                                                        weapons.push_back(w);
                                                        exit = true;
                                                }
                                        }
                                }else if(temp=="potion") {
                                        Potion p;
                                        string s;
                                        bool exit = false;
                                        while(!exit) {
                                                getline(inputFile,s);
                                                if(s.find("Name: ") != string::npos) {
                                                        p.setName(s.substr(s.find(":")+2));
                                                }else if(s.find("Description: ")!=string::npos) {
                                                        p.setDescription(s.substr(s.find(":")+2));
                                                }else if(s.find("Function: ")!=string::npos) {
                                                        p.setHp(stoi(s.substr(s.find(":")+2)));
                                                }else{
                                                        potions.push_back(p);
                                                        exit = true;
                                                }
                                        }
                                }
                        }
                }
                inputFile.close();
        }

}

void readMonster(vector<Monster> &monsters){
        ifstream inputFile("monster.txt");
        if(!inputFile) {
                cerr<<"File not found"<<endl;
        }
        if(inputFile.is_open()) {
                while(!inputFile.eof()) {
                        Monster m;
                        string t;
                        getline(inputFile,t);
                        if(t.find("Name: ") != string::npos) {
                                m.setName(t.substr(t.find(":")+2));
                                bool exit = false;
                                while(!exit) {
                                        string s;
                                        getline(inputFile,s);
                                        if(s.find("Attack: ") != string::npos) {
                                                m.setAttack(stoi(s.substr(s.find(":")+2)));
                                        }else if(s.find("HP: ") != string::npos) {
                                                m.setHp(stoi(s.substr(s.find(":")+2)));
                                        }else if(s.find("Exp: ") != string::npos) {
                                                m.setExperience(stoi(s.substr(s.find(":")+2)));
                                        }else{
                                                exit = true;
                                                monsters.push_back(m);
                                        }
                                }
                        }
                }

                inputFile.close();
        }

}


void intro(){
        cout<<"\n\nInstruction:"<<endl;
        cout<<"1. This is an RPG game, you creat your own character and start as a warrior."<<endl;
        usleep(1500);
        cout<<"2. There will be a job advancment when you reach lv5. You can choose to be a Crusader, Dark Knight or Paladin."<<endl;
        usleep(1500);
        cout<<"3. There are total 12 maps and you will encounter monster in each map. Try your best to defeat them."<<endl;
        usleep(1500);
        cout<<"4. Monsters and bosses will drop value weapons and potions, as well as giving you experience to level up."<<endl;
        usleep(1500);
        cout<<"5. Defeat the last boss and you will win."<<endl;
        usleep(1500);
        cout<<endl;
        cout<<"Prolouge:"<<endl;
        cout<<"The mighty boss, Horntail brought deadly harm to your village."<<endl;
        usleep(1500);
        cout<<"You wanted to save your village from the disaster and decided to step on the dangerous journey as a warrior to defeat Horntail.\n"<<endl;
}

void createChar(Character &c){
        string name;

        cout<<"In Game Name: ";
        getline(cin, name);
        c.setName(name);
        string job = "Warrior";
        c.setJob(job);
        string skill = "";
        c.setSkill(skill);
        int lv = 1;
        c.setLv(lv);
        int currenthp = 50;
        c.setCurrenthp(currenthp);
        // vector<int> maxhp = {50,80,100,120,150,200,220,240,260,300};
        vector<int> maxhp;
        maxhp.push_back(50);
        maxhp.push_back(80);
        maxhp.push_back(100);
        maxhp.push_back(120);
        maxhp.push_back(150);
        maxhp.push_back(200);
        maxhp.push_back(220);
        maxhp.push_back(240);
        maxhp.push_back(260);
        maxhp.push_back(300);

        c.setMaxhp(maxhp);
        int attack = 5;
        c.setAttack(attack);
        int currentexp = 0;
        c.setCurrentexp(currentexp);
        // vector<int> maxexp = {10,30,50,80,100,120,150,200,250,300};
        vector<int> maxexp;
        maxexp.push_back(30);
        maxexp.push_back(50);
        maxexp.push_back(80);
        maxexp.push_back(100);
        maxexp.push_back(120);
        maxexp.push_back(150);
        maxexp.push_back(200);
        maxexp.push_back(250);
        maxexp.push_back(300);

        c.setMaxexp(maxexp);
        Weapon wp("wooden sword","made by wooden obviously",3);
        vector<Weapon> weapons;
        weapons.push_back(wp);
        c.setWeapons(weapons);
        c.setWeapon(wp);
}

void inGame(vector<Room> &rooms,vector<Potion> &potions,vector<Weapon> &weapons,vector<Monster> &monsters,Character &c){
        bool end = false;
        // while(!end) {
        //
        // }
        for (Room r : rooms)
        {
          cout << r.toString() <<endl;
        }

        for (Potion p : potions)
        {
          cout << p.toString() <<endl;
        }

        for (Weapon w : weapons)
        {
          cout << w.toString() <<endl;
        }

        for(Monster m : monsters)
        {
          cout << m.getName() << endl;
        }
}
