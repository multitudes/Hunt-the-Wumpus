#pragma once
//  Cave.hpp
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
//#include "Cave.cpp"


// declaration of cave
// there are 20 rooms so the game board it will be an array of type
// room with 20 rooms, in the array from 0-19 and in the game 1-20.


class Cave{
public:
    Cave();             //constructor
    ~Cave();            // destructor
    int accessCave(int room,int connection); // here the first room is 0
    
private:
    static const int rooms = 20;                // these are constant because not meant to change. they are given by the layout.
    static const int connections = 3;
     // hardcoded values of dodecahedron in a 2 dim vector
    int cave[rooms][connections]={2,5,8,1,3,10,2,4,12,3,5,14,1,4,6,
        5,7,15,6,8,17,1,7,9,8,10,18,2,9,11,10,12,19,3,11,13,12,14,20,4,13,15,6,14,16,15,17,20,7,16,18,9,17,19,11,18,20,13,16,19};
};
