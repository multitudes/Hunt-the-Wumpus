//
//  main.cpp
//  Hunt the Wumpus
//
//  Created by laurence on 15/11/2018.
//  Copyright © 2018 laurence. All rights reserved.
//

#include <iostream>
#include <ctime> 
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
#include "functions.hpp"
#include "Arrows.hpp"

int main() {
    char again;               // initialize the var to continue or not at the end of the game
    
    do
    {
 
    
        
    Cave wumpuscave;                //initialize cave
    Arrows arrows(5);                  // initialize arrows to 5
    vector <Player> players(6);     // six players - me and the hazards which are the wumpus the 2 bats and the 2 pits

    // I associate the 6 players to a vector which will be associated with 6 unique random room numbers
    vector<int>vr{0,0,0,0,0,0}; // I initialize the vector with 0 which is a room number which should not be in the final vector, just to check!
    vector <int> connxRooms(3);             // declare a vector to keep track of connecting rooms
    initPlayersToTheRooms(players,vr);      // this function will fill vr with unique values and initialize the players with the rooms
    
    //start the game. Print title.
    cout << endl << "HUNT THE WUMPUS"<< endl;
   
     // put instruction loop here
    cout << endl << "INSTRUCTIONS (Y-N)\n"<< endl;
    char answerChar = getAnswerChar();
        if (answerChar == 'Y' || answerChar == 'y') printInstructions() ;
        cout << endl;
        
        
    while(true){
        
    checkHazard(wumpuscave,players);            // check if hazards are in connecting rooms
    printMyRoom(players);                       // print the room I am in
    setConnxRooms(wumpuscave,players,connxRooms);   // given the cave layout I update the connxRoom vector with the actual connecting rooms
    printTunnels(connxRooms);                       // I print the connxRoom vector

    // CHOOSE OPTION
    cout <<  "SHOOT OR MOVE (S-M)? ";
    //cin.clear(); cin.ignore();
        char answerChar = getAnswerChar();
    // if MOVE
    if (answerChar=='M'||answerChar=='m'){
        cout << "WHERE TO? ";
        int n = getAnswerIntRoom(connxRooms);
        
        cout << endl;
        players[0].setroom(n);
        if (check_occupant(wumpuscave,players,connxRooms)== 1){
            cout << "TSK TSK TSK- WUMPUS GOT YOU!\n";break;};
        if (check_occupant(wumpuscave,players,connxRooms)== 4 || check_occupant(wumpuscave,players,connxRooms) ==5 ){
            cout << "YYYIIIIEEEE . . . FELL IN PIT\n";
            cout << "HA HA HA - YOU LOSE!\n"; break;};
        if (check_occupant(wumpuscave,players,connxRooms)== 2 || check_occupant(wumpuscave,players,connxRooms) ==3 ){
            cout << "ZAP--SUPER BAT SNATCH! ELSEWHEREVILLE FOR YOU!\n\n";
            // random new room
            newRandomRoom(players,vr);};
    };
   
        // if SHOOT
        if (answerChar=='S'||answerChar=='s'){
            cout << "ROOM # ";
            int n = getAnswerIntRoom(connxRooms);
            cout << endl;
            if (arrows.shootArrow(n, players[1]) == true) {
                youKilledTheWumpus();         // n is my room number and I already checked that it is a connecting room. Players[1] is the Wumpus
                break;
            }
                //else
            
            else {
                if (youMissedArrowRoutine(players,arrows) == 1) break;                    // the crooked arrow will go at random through 4 more rooms and the Wumpus will move one room. Eventually the arrow might kill you on the way.
                
                moveWumpusRoutine(wumpuscave, players, connxRooms);
                cout << players[1].whichRoom();
                // i check again if by chance the Wumpus went into my room!
                if (check_occupant(wumpuscave,players,connxRooms)== 1){
                    cout << "TSK TSK TSK- WUMPUS GOT YOU!\nYOU LOSE! \n\n";break;};
                
            }
            }
        
            };
        
        // CHOOSE if continue
        cout <<  "CONTINUE (Y-N)? ";
        //cin.clear(); cin.ignore();
        again = getAnswerChar();
        
    } while (again == 'y' || again == 'Y');
        //end main
        };

    
    
    
