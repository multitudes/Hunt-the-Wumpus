//
//  Player.cpp
//  Hunt the Wumpus
//
//  Created by laurence on 15/11/2018.
//  Copyright © 2018 laurence. All rights reserved.
//

#include "Player.hpp"
#include "Cave.hpp"
#include "functions.hpp"
#include <random>


Player::Player(){} //constructor


Player::~Player(){}            //destructor

bool Player::checkWumbus()
{
    
    return true;
}
void Player::setroom(int room_num )
{
    room=room_num;
    
}
int Player::whichRoom()
{
    return room;
}


