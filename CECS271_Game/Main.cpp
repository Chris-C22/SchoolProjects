#include <iostream>
#include <algorithm>
#include <string>
#include "Game.h"


using namespace std;

int main()
{	
  //creates game object
  Game start;
  
  cout << "WELCOME TO BATTLESHIP!\n";

  string should_play;

  //prompts user to start game
  cout << "Would you like to play a match vs. the computer? (Y/N)"<<endl;
  cin >> should_play;

  //gives platers a choice
  if (should_play == "Y" || should_play == "y"){
    start.GameStart();
  } 
  else{
    cout << "Come again next time"<<endl;
  }
  
}

