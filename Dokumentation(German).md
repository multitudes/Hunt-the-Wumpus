Laurent Brusa. 

### Aufgabe: Entwickeln Sie eine Konsolen-Applikation.  

# Documentation : Hunt the Wumpus. 

## Vorgeschichte:  
Hunt the Wumpus ist ein frühes textbasiertes Computerspiel von Gregory Yob aus dem Jahr 1972. Das (oder der) Wumpus ist ein fiktives Monster, das in einem Labyrinth von Höhlen und Gängen lebt. Der Spieler muss sich im Textmodus durch die mit Fallen versehenen Höhlen navigieren und durch Auswahl einer Handvoll Optionen versuchen, das Wumpus zur Strecke zu bringen, bevor es ihn selbst verspeist. Außer dem Wumpus noch ein bodenloses Loch und den Spieler teleportierende Fledermäuse.  
Wumpus ist auf vielen Systemen programmiert und umgesetzt worden. Es ist unter anderem Bestandteil der BSD-Games für UNIX und Linux.  
1981 hat Texas Instruments für seinen Home-Computer Texas Instruments TI-99/4A eine grafische Version herausgebracht.  

## Einsatzbereich:  
Dieses Spiel wurde ursprünglich in Basic geschrieben und ich wollte eine C++ Version schreiben, die nah möglich zum Original treu bleibt.  
Die Meldungen und Texteingaben sind gleich geblieben. Das Spiel hat aber Klassen bekommen und wurde vom Code her natürlich komplett umgeschrieben.  

## Gameplay   
  
  
Diese Version ist wie ursprüngliche Version von Hunt the Wumpus Textbasiert. Der Spieler gibt Befehle ein, um sich durch die Räume zu bewegen oder "gekrümmte Pfeile" entlang eines Tunnels in einen der angrenzenden Räume zu schießen. Es gibt zwanzig Räume, die jeweils mit drei anderen verbunden sind und wie die Ecken eines Dodekaeders angeordnet sind. Zu den Gefahren zählen bodenlose Schächte, Superfledermäuse (die den Spieler an einem zufälligen Ort ablegen und der Wumpus selbst. Der Wumpus wird beschrieben, als hätte er Saugfüße (um den bodenlosen Schächten zu entgehen) und zu schwer für eine Superfledermaus, um ihn anzuheben. Wenn der Spieler aus Hinweisen abgeleitet hat, in welcher Kammer sich der Wumpus befindet, ohne die Kammer zu betreten, feuert der Spieler einen Pfeil in die Kammer des Wumpus, um ihn zu töten. Der Spieler gewinnt das Spiel, wenn der Wumpus getötet wird. Das Abfeuern des Pfeils in die falsche Kammer erschreckt den Wumpus jedoch, was dazu führen kann, dass er sich in einen benachbarten Raum bewegt. Der Spieler verliert, wenn er oder sie sich im selben Raum wie der Wumpus (der ihn oder sie dann isst) oder eine bodenlose Grube (in die er oder sie fällt) befindet.

### Verwendete Unterprogramme und Klassen.  
Ich habe 3 Klassen: Cave , Players , Arrows.  
Alle Klassen haben einen standard Konstruktor und Destruktor.  
Cave enthält das Layout von dem Spiel als 2-Dimensionale Vektor. Die erste Dimension speichert die Zimmernummern und die zweite die jeweils angrenzenden Räume. Die Methoden accessCave() gibt mir Zugang zu den gespeicherten Daten.
Players enthält die Zimmernummer von dem Spieler, von den 2 Superfledermäusen, von den bodenlosen Schächten und von dem Wumpus.
Die Methoden sind setroom(), um dem Player eine neue Zimmernummer zuzuordnen, und whichRoom() das mir die Zimmernummer zurueckgibt.
Die Player sind in dem Spiel als Vektor von null bis 5 gespeichert, in die Reihenfolge : Spieler, Wumpus, Superfledermäusen (2,3), und bodenlosen Schächten (4,5)

Arrows enthält die Pfeilenzahl und die Methoden um die Pfeilenzahl upzudaten: updateArrows(), und die Methode shootArrow() die ueberprüft op die Pfeile den Wumpus getroffen hat, die Methode getArrowsNum() um zu wissen wieviele Pfeile übrig sind.

### Die Functionen sind in einen functions.cpp und functions.hpp definiert bzw. deklariert.  
- printTitle() ist einfach eine Willkommenseite.  
- getInstructions() fragt ob der User die Dokumentation lesen will.  
- setConnxRooms() abhaengig von dem Raum in dem ich bin, diese Function wird mein connxRooms vector mit den werten von den 3 angrenzenden Räume updaten.  
- checkHazard() muss checken op in einem der 3 angrenzenden Räume entweder ein Wumpus, eine Superfledermaus oder eine bodenlose Schacht sich befindet. Wenn so dann wird die Meldung rausgegeben :I SMELL A WUMPUS! , BATS NEARBY! oder I FEEL A DRAFT!.  
- ShootOrMove() einfach eine Helperfunction um die mainfunction zu entlasten. Es wird gefragt nach Eingabe von “S” für schiessen oder “M” für schiessen. 
- moveRoutine() Mein Player bewegt sich dann ein Raum weiter und diese Function check ob in dem Raum ein Wumpus, Superfledermäusen, oder schächten sich befinden  
- check_occupant() wird in der moveRoutine() benutzt um zu checken wer sich in dem Raum befindet   
- getAnswerChar() ist eine Helperfunction um ein char input zu bekommen.  
- getAnswerIntRoom() ist eine Helperfunction um ein int input zu bekommen.   
- printTunnels() drückt die angrenzenden Räume aus.  
- newRandomRoom() wenn der Player von der Superfledermaus teletransportiert wird dann bekommt er einen neuen Raum 
- printMyRoom() Konsoleausgabe von meinem Raum   
- shootArrowRoutine() wenn ein Pfeil geschossen wird, wird durch diese Funktion gecheckt ob den Wumpus getroffen wurde, oder wenn der Pfeil zurück kam, ob der Player dadurch getroffen worden ist.  
- youKilledTheWumpus() Unterfunction von shootArrowRoutine(). Wird einfach auf die Konsole die Meldung rausgegeben. 
- youMissedArrowRoutine() Unterfunction von shootArrowRoutine(). Veschiedene Meldungen werden ausgegeben und hier wird gecheckt ob man sich selbst geschossen hat.  
- moveWumpusRoutine() wenn man geschossen hat und nicht getroffen, dann der Wumpus bewegt sich zum nächsten Raum.  
- printInstructions()  Nur die Einfache Konsoleausgabe von den Spielanweisungen.  
