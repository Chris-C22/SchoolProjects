#include <iostream>
#include <string>

#ifndef SHIP_H
#define SHIP_H

class ship 
{

	public:
		void inputShip(int s, std::string n); //user input for coordinates
    void randomShip(int s, std::string n); //ai input for coordinates

		//Getters
		char getrow1(){
    return row1;
    };

		int getcolumn1(){
    return column1;
    };

		char getrow2(){
    return row2;
    };

		int getcolumn2(){
    return column2;
    };

	private:
		//Coordinates for nose of ship
		char row1;
		int column1;

		//Coordinates for end of shop
		char row2;
		int column2;
	
		int size; 
		std::string name; 
	

};



#endif
