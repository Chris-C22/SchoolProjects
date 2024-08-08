#include <iostream>
#include <algorithm>
#include <string> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include "ship.h"

using namespace std;

void ship::inputShip(int s, string n) //gives size and name
{
	cout << "Entering X & Y Coordinates for: " << n << " (" << s <<" units)" << endl;
	size = s; //size of ship
	
	cout << "Where would you like to place the nose of the ship? (Ex. A3)"<<endl;
	cin >> row1; //char
	cin >> column1;//int
	row1 = toupper(row1);
	
	while(cin.fail() || column1 > 10 || column1 < 1 || row1 < 'A' || row1 >'J') 
	{
		cout << "Where would you like to place the nose of this ship? (Ex. A3)"<<endl;
	  cin >> row1; //char
	  cin >> column1;//int
	  row1 = toupper(row1);
	}
	
	cout << "How will you orient the ship? Up(1), Down(2), Left(3), or Right(4)?" << endl;
	string input; //option
	bool validated = true;//ensures position is okayy
  cin >> input;
	
	do{ //do while - loop while validated !=true
		for (int i=0; input[i]; i++){ 
      input[i] = tolower(input[i]); 
      }
    //verifies input of 1-4
		while(input != "1" && input != "2" && input != "3" && input != "4") 
		{
			cin >> input;
			for (int i=0; input[i]; i++){
      input[i] = tolower(input[i]);
        }
		}
		
		//Verify size and accounts for 0 value 
		int length = size -1;
		
		if(input == "1")
		{
			if((row1 - length) < 'A') { //if rear  exceeds the border
      cout << "Does not fit"<< endl;
      }else{
				row2 = row1 - length; //gives a higher position to rear of ship
				column2 = column1; //remain in same column - horizontal
				validated = true; //is okay
			}
		}
	
		if(input == "2")
		{
			if((row1 + length) > 'J') { // if rear exceeds border
        cout << "Does not fit"<< endl;
        }
			else
			{
				row2 = row1 + length; //gives lower postion to rear of ship
				column2 = column1;  //remain in same column - horizontal
				validated = true; //is okay
			}
		}
	
		if(input == "3")
		{
			if((column1 - length) < 1) { //if rear exceeds border
        cout << "Does not fit"<< endl;
        }
			else
			{
				column2 = column1-length; //puts coordinate for rear off ship further left than front
				row2 = row1; //remain in same row
				validated = true; // its okay
			}
		}
	
		if(input == "4")
		{
			if((column1 + length) > 10) 
      {cout << "Does not fit"<< endl;
        }
			else
			{
				column2 = column1 + length;//puts coordinate for rear off ship further right than front
				row2 = row1; //same row 
				validated = true;//its okay
			}
		}
	}while (validated != true);//loop if its not in an okay position


  //makes sure that the rear of ship is always "trailing" front of the ship
  if(row1 > row2)
        swap(row1, row2);
    if(column1>column2)
        swap(column1, column2);

}

//
//nearly identical to inputShip except values for ships are randomly generated
void ship::randomShip(int s, string n) 
{
	size = s;
  
  srand (time(NULL)); //starts random
  
  column1  = rand() %10; //choose random column A - J
  row1 = 'a' + rand()%10; //random row 1-10
  row1 = toupper(row1); //convert lower case to upper case

  //copied from prev function, ensures correct input
	while(column1 > 10 || column1 < 1 || row1 < 'A' || row1 >'J') 
	{
    //repeat random generation
    column1  = rand() %10;
    row1 = 'a' + rand()%9;
    row1 = toupper(row1);
	}

  bool validated = true;
	do{
      //chooses if the ship will be up, down, left right
      int direction = rand() % 5;
    	string option;
      
    	//Places ships based on random int
    	switch(direction)
    	{
        case 1:
          option ="1";
          break;
        case 2:
          option ="2";
          break;
        case 3:
          option ="3";
          break;
        case 4:
          option ="4";
          break;
        default:
          option = "1";
          break;    
        }
    
    string input = option;
		for (int i=0; input[i]; i++){
      input[i] = tolower(input[i]);
      }

    //if not "1-4", repeat process as above
		while(input != "1" && input != "2" && input != "3" && input != "4") 
		{
			  int direction = rand() % 5;
	      string option;
  
    	//random ship orientation
    	switch(direction)
    	{
        case 1:
          option ="1";
          break;
        case 2:
          option ="2";
          break;
        case 3:
          option ="3";
          break;
        case 4:
          option ="4";
          break;
        default:
          option = "1";
          break;    
        }

      string input = option;
			for (int i=0; input[i]; i++){
        input[i] = tolower(input[i]);
        }
		}
		
		int length = size -1;

		if(input == "1")
		{
			if((row1 - length) < 'A') {
      }else{
				row2 = row1 - length;
				column2 = column1;
				validated = true;
			}
		}
	
		if(input == "2")
		{
			if((row1 + length) > 'J') {
        }
			else
			{
				row2 = row1 + length;
				column2 = column1;
				validated = true;
			}
		}
	
		if(input == "3")
		{
			if((column1 - length) < 1) {
        
      }
			else
			{
				column2 = column1-length;
				row2 = row1;
				validated = true;
			}
		}
	
		if(input == "4")
		{
			if((column1 + length) > 10) {
        
      }
			else
			{
				column2 = column1 + length;
				row2 = row1;
				validated = true;
			}
		}
	}while (validated != true);
	if(row1 > row2)
        swap(row1, row2);
    if(column1>column2)
        swap(column1, column2);
  }
