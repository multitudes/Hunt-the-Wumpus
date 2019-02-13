#pragma once
//  Link.hpp
//  Hunt the Wumpus
//
//  Created by onespeedvelo on 15/11/2018.
//  Copyright © 2018 laurence. All rights reserved.
//

#ifndef Link_hpp
#define Link_hpp

#include <stdio.h>

#endif /* Link_hpp */
#include <string>
using namespace std;
#include <vector>
#include <iostream>
#include "Cave.hpp"
#include "Player.hpp"


int random_int(int min,int max);
void initialize_locations(vector<int>& vr);

void locatePlayers(Player& player,int room);
void initPlayersToTheRooms(vector<Player>& players, vector<int>& vr);
int checkHazard(Cave& wumpuscave, vector<Player>& players);

char getAnswerChar();
void setConnxRooms(Cave& wumpuscave,vector<Player>& players,vector<int>& connxRooms);
void printTunnels(vector<int>& connxRooms);
int getAnswerIntRoom(vector<int>& connxRooms);
int check_occupant(Cave& wumpuscave,vector<Player>& players,vector<int>& connxRooms);

void newRandomRoom(vector<Player>& players, vector<int>& vr);

/*
class Link{
public:
    int value;   // number of the room
    // now constructor initializing
    Link(const int& v, Link* p = nullptr, Link* n1 = nullptr, Link* n2 = nullptr)
    : value(v), prev(p), next1(n1), next2(n2) {
    // no vector after all vector<Room>cave(20);
    }
    Link(int v):value(v){};
    Link ();
    Link advance(Link* n);
    
//private:
    
    Link* prev;
    Link* next1;
    Link* next2;
};

class Cave{
public:
    Cave();
    void initialize_cave();
    int accessCave(int room,int connection);
private:
    static const int rooms = 20;
    static const int connections = 3;
    int cave[rooms][connections]={2,5,8,1,3,10,2,4,12,3,5,14,1,4,6,
        5,7,15,6,8,17,1,7,9,8,10,18,2,9,11,10,12,19,3,11,13,12,14,20,4,13,15,6,14,16,15,17,20,7,16,18,9,17,19,11,18,20,13,16,19};
};

*/

/*
class Link {
public:
    string value;
    
    Link(const string& v, Link* p = 0, Link* s = 0)
    : value(v), prev(p), succ(s) { }
    
    Link* insert(Link* n) ;   // insert n before this object
    Link* add(Link* n) ;      // insert n after this object
    Link* erase() ;           // remove this object from list
    Link* find(const string& s);    // find s in list
    const Link* find(const string& s) const; // find s in list
    
    Link* advance(int n) const;     // move n positions in list
    
    Link* next() const { return succ; }
    Link* previous() const { return prev; }
private:
    Link* prev;
    Link* succ;
};
*/
