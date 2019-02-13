#pragma once
//  Players.hpp
//  Hunt the Wumpus
//
//  Created by onespeedvelo on 15/11/2018.
//  Copyright © 2018 laurence. All rights reserved.
//

#ifndef Players_hpp
#define Players_hpp

#include <stdio.h>

#endif /* Players_hpp */

#include <string>
using namespace std;
#include <vector>
#include <iostream>
#include "Cave.hpp"



class Player{
public:
    Player();                                       //default constructor
    ~Player();                                      //destructor
    void setroom(int room_num);
    int whichRoom();
    bool checkWumbus();
    
private:
    int arrows = 5;  // game starts with 5 arrows
    int room;   // where the player is located
    // int prev,next1,next2; // here I store the adjacent rooms but actually  they are already in the array ..?
};



