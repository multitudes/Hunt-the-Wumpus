#pragma once
//  functions.hpp
//  Hunt the Wumpus
//
//  Created by onespeedvelo on 15/11/2018.
//  Copyright © 2018 laurence. All rights reserved.
//

#ifndef Cave_hpp
#define Cave_hpp

#include <stdio.h>

#endif /* Cave_hpp */
#include <string>
using namespace std;
#include <vector>
#include <iostream>
#include "Cave.hpp"
#include "Player.hpp"
#include "Arrows.hpp"


int random_int(int min,int max);    // create a random int with min max for the room 0-20 or for the location 0-6

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
void youKilledTheWumpus();
void printMyRoom(vector<Player>& players);
int youMissedArrowRoutine(vector<Player>& players, Arrows a);
void moveWumpusRoutine(Cave& wumpuscave,vector<Player>& players,vector<int>& connxRooms);

void printInstructions();
