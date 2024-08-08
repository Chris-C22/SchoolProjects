#ifndef GAME_H
#define GAME_H
#include "Field.h"
#include "ship.h"

class Game
{
public:

  //function to start game
  void GameStart();

  //initialization of fields
	Field playerField; 
	Field copyField; 
	Field opponentField; 
	
	//initialization of player/enemy ships
	ship playerDestroyer;
	ship playerSubmarine;
	ship playerCruiser;
	ship playerBattleship;
	ship playerAircraftCarrier;

  ship opponentDestroyer;
	ship opponentSubmarine;
	ship opponentCruiser;
	ship opponentBattleship;
	ship opponentAircraftCarrier;

private:

};

#endif // GAME_H
