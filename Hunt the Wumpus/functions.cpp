//
//  functions.cpp
//  Hunt the Wumpus
//
//  Created by laurence on 15/11/2018.
//  Copyright © 2018 laurence. All rights reserved.
//

#include "Player.hpp"
#include "Cave.hpp"
#include "functions.hpp"
#include <random>
#include "Arrows.hpp"



void locatePlayers(Player& player,int room)
{
    player.setroom(room);
}

int random_int(int min,int max)              // create a random int with min max for the room 0-20 or for the location 0-6
{
    static random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<> dist(min, max);
    return dist(mt);
}


void initialize_locations(vector<int>& vr)     // vr vector passed as reference will be filled with 6 distinct unique room numbers
{
    
    //double min=1;double max = 20; total 20 rooms
    
    int temp = 0; int min = 1; int max = 20;
    for (int j=0 ; j<6 ; j++)
    {
        while(true)
        {
            temp=random_int(min,max);
            if (find(vr.begin(), vr.end(), temp)!=vr.end())continue;
            
            vr[j]=temp;
            
            cout<<vr[j]<<" ";
            break;
        };
    };
}

/* int hunter=player[0]; 
 wumpus=player[1]; bat1=player[2]; bat2=player[3]; pit1=player[4]; pit2=player[5];
 */
void initPlayersToTheRooms(vector<Player>& players, vector<int>& vr)
{
    
    initialize_locations(vr); // first the int vector with the 6 room nums
    // here i associate the random room nums with the players
    for (int j=0 ; j<6 ; j++)
    {
        locatePlayers(players[j],vr[j]);
        cout<< endl;
        cout<<"player "<< j << " : " <<players[j].whichRoom();
        cout<< endl;
    }
}

int checkHazard(Cave& wumpuscave,vector<Player>& players)           // given the position of player check if there are hazards nearby
{
    int myRoom =players[0].whichRoom();
    //cout << myRoom;
    int hazardRoom =players[1].whichRoom();
    //cout <<"hazardroom : W "<<hazardRoom << endl;
    
    for ( int i = 0; i < 3; i++){
        int connxRoom = wumpuscave.accessCave(myRoom-1,i);
        //cout << connxRoom<<" ";
        if (connxRoom==hazardRoom)
        {cout<< "I SMELL A WUMPUS!\n";break;};}
    
    int hazardRoom1 =players[2].whichRoom();
    //cout <<"hazardroom B1 : "<< hazardRoom1 << endl;
    int hazardRoom2 =players[3].whichRoom();
    //cout <<"hazardroom B2 : "<< hazardRoom2 << endl;
    for ( int i = 0; i < 3; i++){
        int connxRoom = wumpuscave.accessCave(myRoom-1,i);
        //cout << connxRoom<<" ";
        if (connxRoom==hazardRoom1 || connxRoom==hazardRoom2)
        {cout<< "BATS NEARBY!\n";break;};}
    
    int hazardRoom3 =players[4].whichRoom();
    //cout <<"hazardroom P1 : "<< hazardRoom3 << endl;
    int hazardRoom4 =players[5].whichRoom();
    //cout <<"hazardroom P2 : "<< hazardRoom4 << endl;
    for ( int i = 0; i < 3; i++){
        int connxRoom = wumpuscave.accessCave(myRoom-1,i);
        //cout << connxRoom<<" ";
        if (connxRoom==hazardRoom3 || connxRoom==hazardRoom4)
        {cout<< "I FEEL A DRAFT!\n";break;};}
    
    return 0;
}
int check_occupant(Cave& wumpuscave,vector<Player>& players,vector<int>& connxRooms){
    int myRoom =players[0].whichRoom();
    for (int i = 1; i < 6 ; i++)
        if (myRoom == players[i].whichRoom())return i;
    return 0;
}

char getAnswerChar()
{
    char n ;
    while (true){
        if (cin>>n){
            if(n=='S'||n=='M'||n=='y'||n=='Y'||n=='s'||n=='m'||n=='n'||n=='N'||(int (n)>=1 && int(n)<=20))return n;
            cout<<"\nNOT A VALID INPUT, TRY AGAIN :  ";
        }
    }
}

void printTunnels(vector<int>& connxRooms){
    cout <<"TUNNELS LEAD TO " << connxRooms[0] << "   " <<connxRooms[1]<< "   " << connxRooms[2] << endl << endl;
}

int getAnswerIntRoom(vector<int>& connxRooms){         // getting the rooms to move or sort into - this is for input error management
    int n = 0;
    string s;                   // in case cin fails the buffer will be saved in s and cleared
    while (true){
    while(!(cin >> n))
    {
        cin.clear();
        cin >> s;
        cout << "\nNOT A VALID NUMBER, TRY AGAIN :  ";
    }
    if( n==connxRooms[0] || n == connxRooms[1] || n == connxRooms[2] )return n;
    else{
        cout<<"\nNOT A VALID CONNECTING ROOM, TRY AGAIN :  ";
            }
    
    }
}

void setConnxRooms(Cave& wumpuscave,vector<Player>& players,vector<int>& connxRooms){
    connxRooms[0]=wumpuscave.accessCave(players[0].whichRoom()-1,0);
    connxRooms[1]=wumpuscave.accessCave(players[0].whichRoom()-1,1);
    connxRooms[2]= wumpuscave.accessCave(players[0].whichRoom()-1,2);
};

void newRandomRoom(vector<Player>& players,vector<int>& vr){
    //double min=1;double max = 20; total 20 rooms
    
    int temp = 0; int min = 1; int max = 20;
    {
        while(true)
        {
            temp=random_int(min,max);
            if (find(vr.begin(), vr.end(), temp)!=vr.end())continue;
            vr[0]=temp;
            locatePlayers(players[0],vr[0]);
            break;
        };
    };
    
    
};

void printMyRoom(vector<Player>& players){
    cout << "YOU ARE IN ROOM " << players[0].whichRoom() << endl;
}

void youKilledTheWumpus(){
    cout << "AHA! YOU GOT THE WUMPUS!\n";
    cout << "HEE HEE HEE - THE WUMPUS'LL GETCHA NEXT TIME!!\n";
}

int youMissedArrowRoutine(vector<Player>& players, Arrows a){
    cout << " MISSED ! \n\n";
    cout << "YOU HAVE "<< a.getArrowsNum() << " ARROWS LEFT. \n";
    cout << "...OOPS! BUMPED A WUMPUS!\n\n";
    
    int me = players[0].whichRoom();
    int random = 21 ;
    for (int j=0 ; j<5 ; j++){
        random = random_int(1,20);
        if (me == random) {cout << "OUCH! ARROW GOT YOU! YOU LOSE! \n\n";
            return 1;
        }
    }  return 0;
}

void moveWumpusRoutine(Cave& wumpuscave,vector<Player>& players,vector<int>& connxRooms){
    int random = random_int(0,2);
    // players[1] is the Wumpus and I set new room looking into the cave array and he will move to one of his 3 connecting rooms
    players[1].setroom(wumpuscave.accessCave(players[1].whichRoom()-1,random));
    
};

void printInstructions(){
    cout << "\nWELCOME TO 'HUNT THE WUMPUS' \n";
    cout << "  THE WUMPUS LIVES IN A CAVE OF 20 ROOMS. EACH ROOM\n";
    cout <<  "HAS 3 TUNNELS LEADING TO OTHER ROOMS. (LOOK AT A \n";
    cout <<  "DODECAHEDRON TO SEE HOW THIS WORKS-IF YOU DON'T KNOW\n";
    cout <<  "WHAT A DODECAHEDRON IS, ASK SOMEONE)\n\n";
    
    cout <<  "     HAZARDS: \n";
    cout <<  " BOTTOMLESS PITS - TWO ROOMS HAVE BOTTOMLESS PITS IN THEM\n";
    cout <<  "     IF YOU GO THERE, YOU FALL INTO THE PIT (& LOSE!)\n";
    cout <<  " SUPER BATS - TWO OTHER ROOMS HAVE SUPER BATS. IF YOU\n";
    cout <<  "     GO THERE, A BAT GRABS YOU AND TAKES YOU TO SOME OTHER\n";
    cout <<  "     ROOM AT RANDOM. (WHICH MIGHT BE TROUBLESOME)\n";
    
    cout <<  "     WUMPUS:\n";
    cout <<  " THE WUMPUS IS NOT BOTHERED BY THE HAZARDS (HE HAS SUCKER\n";
    cout <<  " FEET AND IS TOO BIG FOR A BAT TO LIFT).  USUALLY\n";
    cout <<  " HE IS ASLEEP. TWO THINGS WAKE HIM UP: YOUR ENTERING\n";
    cout <<  " HIS ROOM OR YOUR SHOOTING AN ARROW.\n";
    cout <<  "     IF THE WUMPUS WAKES, HE MOVES ONE ROOM\n";
    cout <<  " OR STAYS STILL. AFTER THAT, IF HE IS WHERE YOU\n";
    cout <<  " ARE, HE EATS YOU UP (& YOU LOSE!)\n\n";
    
    cout <<  "     YOU:\n";
    cout <<  " EACH TURN YOU MAY MOVE OR SHOOT A CROOKED ARROW\n";
    cout <<  "   MOVING: YOU CAN GO ONE ROOM (THRU ONE TUNNEL)\n";
    cout <<  "   ARROWS: YOU HAVE 5 ARROWS. YOU LOSE WHEN YOU RUN OUT.\n";
    cout <<  "   EACH ARROW CAN GO THROUGH 5 ROOMS. YOU AIM BY TELLING\n";
    cout <<  "   THE COMPUTER THE ROOM YOU WANT THE ARROW TO GO TO.\n";
    cout <<  "   IF THE ARROW DOESN'T hit the WUMPUS, IT MOVES\n";
    cout <<  "   AT RAMDOM TO THE NEXT ROOMS.\n";
    cout <<  "     IF THE ARROW HITS THE WUMPUS, YOU WIN.\n";
    cout <<  "     IF THE ARROW HITS YOU, YOU LOSE.\n\n";
    
    cout <<  "    WARNINGS:\n";
    cout <<  "     WHEN YOU ARE ONE ROOM AWAY FROM WUMPUS OR HAZARD,\n";
    cout <<  "    THE COMPUTER SAYS:\n";
    cout <<  " WUMPUS-  'I SMELL A WUMPUS'\n";
    cout <<  " BAT   -  'BATS NEARBY'\n";
    cout <<  " PIT   -  'I FEEL A DRAFT'\n\n";
    
}
