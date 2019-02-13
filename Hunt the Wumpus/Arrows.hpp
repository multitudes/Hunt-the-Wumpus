#pragma once
//
//  Arrows.hpp
//  Hunt the Wumpus
//
//  Created by onespeedvelo on 19/11/2018.
//  Copyright © 2018 laurence. All rights reserved.
//

#ifndef Arrows_hpp
#define Arrows_hpp
#include <vector>
#include <stdio.h>
#include "Player.hpp"

#endif /* Arrows_hpp */

class Arrows{

public:
    Arrows(int y);                                       //default constructor
    ~Arrows();            //destructor
    void updateArrows();
    bool shootArrow(int room_num, Player& players);
    int getArrowsNum();
private:
    int arrows;  // game starts with 5 arrows
   };
