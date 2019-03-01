# Hunt-the-Wumpus
A version of 'Hunt The Wumpus' written in C++ 
This is the result of one week coding project and inspired by reading "Programming: Principles and Practice Using C++" by *Bjarne Stroustrup*. He mentioned Hunt the Wumpus in the drill section of chapter 18:
> “Implement a version of the game “Hunt the Wumpus.” “Hunt the Wumpus” (or just “Wump”) is a simple (non-graphical) computer game originally invented by Gregory Yob. The basic premise is that a rather smelly monster lives in a dark cave consisting of connected rooms. Your job is to slay the wumpus using bow and arrow. In addition to the wumpus, the cave has two hazards: bottomless pits and giant bats. If you enter a room with a bottomless pit, it’s the end of the game for you. If you enter a room with a bat, the bat picks you up and drops you into another room. If you enter the room with the wumpus or he enters yours, he eats you. When you enter a room you will be told if a hazard is nearby:
“I smell the wumpus”: It’s in an adjoining room.
“I feel a breeze”: One of the adjoining rooms is a bottomless pit.
“I hear a bat”: A giant bat is in an adjoining room.
For your convenience, rooms are numbered. Every room is connected by tunnels to three other rooms. When entering a room, you are told something like “You are in room 12; there are tunnels to rooms 1, 13, and 4; move or shoot?” Possible answers are m13 (“Move to room 13”) and s13–4–3 (“Shoot an arrow through rooms 13, 4, and 3”). The range of an arrow is three rooms. At the start of the game, you have five arrows. The snag about shooting is that it wakes up the wumpus and he moves to a room adjoining the one he was in — that could be your room.
Probably the trickiest part of the exercise is to make the cave by selecting which rooms are connected with which other rooms. You’ll probably want to use a random number generator (e.g., randint() from std_lib_facilities.h) to make different runs of the program use different caves and to move around the bats and the wumpus. Hint: Be sure to have a way to produce a debug output of the state of the cave.”

Quite sweet. After that I found references to the Wumpus in other places in the web. It turns out that Jeff Atwood (founder of Stackoverflow) mentions the Wumpus on his [coding horrors](https://blog.codinghorror.com/the-history-of-wumpus/) blog.

and I found out later after my project that Brendan Gregg (one of the senior Netflix engineers) on his blog has under specials a version of Wumpus in C: [http://www.brendangregg.com/Specials/](http://www.brendangregg.com/Specials/)

A version of Solaris Unix shipped with the Wumpus as a game, like the Chess game in Mac..
I really enjoyed doing this small exercice. It can be done better, I would love to continue work on it at some time in the future. It would be nice to get a randomized layout at the start of the game. And eventually in version 2 a GUI like in the Texas Instrument version.<br>
<img src="/wumpusm.jpg" alt="drawing" width="400"/>
