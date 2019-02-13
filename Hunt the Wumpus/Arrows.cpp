//
//  Arrows.cpp
//  Hunt the Wumpus
//
//  Created by onespeedvelo on 19/11/2018.
//  Copyright © 2018 laurence. All rights reserved.
//

#include "Arrows.hpp"

Arrows::Arrows(int y): arrows(y){};                // Default constructor
Arrows::~Arrows(){};               // Destructor

void Arrows::updateArrows(){
    
    if (arrows == 1) cout <<"YOU FINISHED YOUR ARROWS! YOU LOSE! \n";
    arrows--;
    
}

bool Arrows::shootArrow(int room_num, Player& players){
    
    if ( room_num == players.whichRoom()) return true;      // check if a hit
    updateArrows();                                         // if not update arrows number
    return false;
}
int Arrows::getArrowsNum(){                 // helper function to return the number of arrows left
    return arrows;
};

