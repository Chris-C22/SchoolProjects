 #include "Game.h"
 #include <iostream>
 #include <algorithm>
 #include <string>
 #include "ship.h"
 #include "Field.h"

  using namespace std;

  void Game::GameStart(){
  bool overlap;
	bool endGame = false; //determine when to end game

	while (!endGame)
	{
		
			playerField.showField();
    
			//Player's destroyer
			playerDestroyer.inputShip(2, "Destroyer");
			playerField.placeShip(playerDestroyer);
			playerField.showField();
	
			//Player's Submarine
			playerSubmarine.inputShip(3, "Submarine");
			overlap = playerField.isOverlap(playerSubmarine);
			while(overlap == true) //checks for any overlap
			{
				cout << "\nError! Your ship overlaps a ship already placed! Please re-enter coordinates" << endl;
				playerField.showField();
				playerSubmarine.inputShip(3, "Submarine");
				overlap = playerField.isOverlap(playerSubmarine);
			}
			playerField.placeShip(playerSubmarine); //Place in Field if no issues
			playerField.showField(); //show 
	
			//Player's Cruiser
			playerCruiser.inputShip(3, "Cruiser");
			overlap = playerField.isOverlap(playerCruiser);
			while(overlap == true)
			{
				cout << "\nError! Your ship overlaps a ship already placed! Please re-enter coordinates" << endl;
				playerField.showField();
				playerCruiser.inputShip(3, "Cruiser");
				overlap = playerField.isOverlap(playerCruiser);
			}
			playerField.placeShip(playerCruiser);
			playerField.showField();

      //Player's Battleship
			playerBattleship.inputShip(4, "Battleship");
			overlap = playerField.isOverlap(playerBattleship);
			while(overlap == true)
			{
				cout<< "\nError! Your ship overlaps a ship already placed! Please re-enter coordinates" << endl;
				playerField.showField();
				playerBattleship.inputShip(4, "Battleship");
				overlap = playerField.isOverlap(playerBattleship);
			}
	
			playerField.placeShip(playerBattleship);
			playerField.showField();
	
	    //Player's Aircraft Carrier
			playerAircraftCarrier.inputShip(5, "Aircraft Carrier");
			overlap = playerField.isOverlap(playerAircraftCarrier);
			while(overlap == true)
			{
				cout<< "\nError! Your ship overlaps a ship already placed! Please re-enter coordinates" << endl;
				playerField.showField();
				playerAircraftCarrier.inputShip(5, "Aircraft Carrier");
				overlap = playerField.isOverlap(playerAircraftCarrier);
			}
			playerField.placeShip(playerAircraftCarrier);
			playerField.showField();

		  cout << endl << "Making AI Field Now..." << endl; 
      //Same process as player except function randomShip to place ships automatically
      //AI Destroyer
			opponentDestroyer.randomShip(2, "Destroyer");
			opponentField.placeShip(opponentDestroyer);
	
			//AI Submarine
			opponentSubmarine.randomShip(3, "Submarine");
			overlap = opponentField.isOverlap(opponentSubmarine);
			while(overlap == true) 
			{

				opponentSubmarine.randomShip(3, "Submarine");
				overlap = opponentField.isOverlap(opponentSubmarine);
			}
			opponentField.placeShip(opponentSubmarine); 

      //AI Cruiser
			opponentCruiser.randomShip(3, "Cruiser");
			overlap = opponentField.isOverlap(opponentCruiser);
			while(overlap == true)
			{
				opponentCruiser.randomShip(3, "Cruiser");
				overlap = opponentField.isOverlap(opponentCruiser);
			}
			opponentField.placeShip(opponentCruiser);

      //AI Battleship
			opponentBattleship.randomShip(4, "Battleship");
			overlap = opponentField.isOverlap(opponentBattleship);
			while(overlap == true)
			{
				
				opponentBattleship.randomShip(4, "Battleship");
				overlap = opponentField.isOverlap(opponentBattleship);
			}
			opponentField.placeShip(opponentBattleship);

      //AI Aircraft Carrier
			opponentAircraftCarrier.randomShip(5, "Aircraft Carrier");
			overlap = opponentField.isOverlap(opponentAircraftCarrier);
			while(overlap == true)
			{
				
				opponentAircraftCarrier.randomShip(5, "Aircraft Carrier");
				overlap = opponentField.isOverlap(opponentAircraftCarrier);
			}
			opponentField.placeShip(opponentAircraftCarrier);

    opponentField.showField();


    //initialize status of game
		bool playerWin = false; 
		bool opponentWin = false;

    //loop until one winner
		while(!playerWin && !opponentWin)
		{
      //shows known board of enemy
			copyField.showField();

			cout << "***YOUR TURN***" << endl;
			copyField = opponentField.playerShot(copyField); 
			playerWin = opponentField.Winner(); //win?
		
			if(!playerWin) 
			{
        //enemy turn
				cout << endl << "***AI TURN***" << endl;
				playerField.opponentShot(); 
				opponentWin = playerField.Winner(); //win?
				cout << "YOUR SHIPS:" << endl;
        //status of player
				playerField.showField();
			}
		}


    //when one of two players has won, will display
		if(playerWin)
		{
			cout << "Player Wins!" << endl;
		}
		else
		{
			cout << "AI Wins!" << endl;
		}
		
	}
	
	cout << "Bye!" << endl;
}
