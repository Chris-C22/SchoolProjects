#include <iostream>
#include "ship.h"

#ifndef FIELD_H
#define FIELD_H

class Field //The game field 
{
  public:
  		Field(); //Constructor
  		void clearField(); //Clears field
  		void showField(); //shows field for player
  
  		void changeField(int index1, int index2, char symbol); //Edits a position in field array
  		bool isOverlap(ship s); //Checks for overlapping ships
  		bool Winner(); //If no ships remain for a player - true
  		void placeShip(ship s); //Places a ship onto the board
  		Field playerShot(Field copyField); //Player Shot - copyField is the copy, then is updated
  		void opponentShot(); //AI shot at player field

	private:

    //Converts
		int charToInt(char c);
		char intToChar(int i);
		
		char field[10][10]; //2D-Array for 10x10 
		
		int opponentShotX;//random x-coordinate
		int opponentShoty;//random y-coordinate		
};

#endif
