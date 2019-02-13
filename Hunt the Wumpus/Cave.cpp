//
//  Cave.cpp
//  Hunt the Wumpus
//
//  Created by laurence on 15/11/2018.
//  Copyright © 2018 laurence. All rights reserved.
//

#include "Cave.hpp"
#include <random>

Cave::Cave()            // Constructor
{
}

Cave::~Cave()            // Destructor
{
}

// Cave is initialized as a 2 dimensional vector. a is the room number abd b are the hardcoded connecting rooms as on the dodecahedre model. This function will allow to get the connecting rooms out of the vector

int Cave::accessCave(int a,int b)
{
    return cave[a][b];
}


