#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#include "Field.h"

// Converts the coordinate "A" to a numerical position on Field
int Field::charToInt(char c) {
  switch (c) {
  case 'A':
    return 1;
  case 'B':
    return 2;
  case 'C':
    return 3;
  case 'D':
    return 4;
  case 'E':
    return 5;
  case 'F':
    return 6;
  case 'G':
    return 7;
  case 'H':
    return 8;
  case 'I':
    return 9;
  case 'J':
    return 10;
  }

  return 0;
}

// Converts back to a letter for output
char Field::intToChar(int i) {
  switch (i) {
  case 1:
    return 'A';
  case 2:
    return 'B';
  case 3:
    return 'C';
  case 4:
    return 'D';
  case 5:
    return 'E';
  case 6:
    return 'F';
  case 7:
    return 'G';
  case 8:
    return 'H';
  case 9:
    return 'I';
  case 10:
    return 'J';
  }

  return 0;
}

// Fills field array with empty spaces
Field::Field() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      field[i][j] = ' ';
    }
  }
}

// Resets field
void Field::clearField() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      field[i][j] = ' ';
    }
  }
}

void Field::showField() // shows field - both player and opponent, and is
                        // updated by copyField
{
  cout << "   1   2   3   4   5   6   7   8   9  10" << endl
       << "A [" << field[0][0] << "] [" << field[0][1] << "] [" << field[0][2]
       << "] [" << field[0][3] << "] [" << field[0][4] << "] [" << field[0][5]
       << "] [" << field[0][6] << "] [" << field[0][7] << "] [" << field[0][8]
       << "] [" << field[0][9] << "]" << endl
       << "B [" << field[1][0] << "] [" << field[1][1] << "] [" << field[1][2]
       << "] [" << field[1][3] << "] [" << field[1][4] << "] [" << field[1][5]
       << "] [" << field[1][6] << "] [" << field[1][7] << "] [" << field[1][8]
       << "] [" << field[1][9] << "]" << endl
       << "C [" << field[2][0] << "] [" << field[2][1] << "] [" << field[2][2]
       << "] [" << field[2][3] << "] [" << field[2][4] << "] [" << field[2][5]
       << "] [" << field[2][6] << "] [" << field[2][7] << "] [" << field[2][8]
       << "] [" << field[2][9] << "]" << endl
       << "D [" << field[3][0] << "] [" << field[3][1] << "] [" << field[3][2]
       << "] [" << field[3][3] << "] [" << field[3][4] << "] [" << field[3][5]
       << "] [" << field[3][6] << "] [" << field[3][7] << "] [" << field[3][8]
       << "] [" << field[3][9] << "]" << endl
       << "E [" << field[4][0] << "] [" << field[4][1] << "] [" << field[4][2]
       << "] [" << field[4][3] << "] [" << field[4][4] << "] [" << field[4][5]
       << "] [" << field[4][6] << "] [" << field[4][7] << "] [" << field[4][8]
       << "] [" << field[4][9] << "]" << endl
       << "F [" << field[5][0] << "] [" << field[5][1] << "] [" << field[5][2]
       << "] [" << field[5][3] << "] [" << field[5][4] << "] [" << field[5][5]
       << "] [" << field[5][6] << "] [" << field[5][7] << "] [" << field[5][8]
       << "] [" << field[5][9] << "]" << endl
       << "G [" << field[6][0] << "] [" << field[6][1] << "] [" << field[6][2]
       << "] [" << field[6][3] << "] [" << field[6][4] << "] [" << field[6][5]
       << "] [" << field[6][6] << "] [" << field[6][7] << "] [" << field[6][8]
       << "] [" << field[6][9] << "]" << endl
       << "H [" << field[7][0] << "] [" << field[7][1] << "] [" << field[7][2]
       << "] [" << field[7][3] << "] [" << field[7][4] << "] [" << field[7][5]
       << "] [" << field[7][6] << "] [" << field[7][7] << "] [" << field[7][8]
       << "] [" << field[7][9] << "]" << endl
       << "I [" << field[8][0] << "] [" << field[8][1] << "] [" << field[8][2]
       << "] [" << field[8][3] << "] [" << field[8][4] << "] [" << field[8][5]
       << "] [" << field[8][6] << "] [" << field[8][7] << "] [" << field[8][8]
       << "] [" << field[8][9] << "]" << endl
       << "J [" << field[9][0] << "] [" << field[9][1] << "] [" << field[9][2]
       << "] [" << field[9][3] << "] [" << field[9][4] << "] [" << field[9][5]
       << "] [" << field[9][6] << "] [" << field[9][7] << "] [" << field[9][8]
       << "] [" << field[9][9] << "]" << endl;
}

// change one position on a field
void Field::changeField(int index1, int index2, char symbol) {
  // Pass point to be changeed
  // this adjust automatically for off-by-one due to 0 as first val
  index1--;
  index2--;
  field[index1][index2] = symbol;
}

// True if # are gone on a field
bool Field::Winner() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (field[i][j] == '#') {
        return false;
      }
    }
  }
  return true;
}

bool Field::isOverlap(ship s) // Detect whether passed ship object would cross
                              // any ships already placed
{
  bool overlap = false;

  // Find coordinates
  int row1 = charToInt(s.getrow1());
  int column1 = s.getcolumn1();
  int row2 = charToInt(s.getrow2());
  int column2 = s.getcolumn2();

  row1--;
  column1--;
  row2--;
  column2--;

  // checks horizontal
  if (row1 == row2) {
    do {
      if (field[row1][column1] == '#') {
        // Found overlap;
        overlap = true;
      }
      column1++;

    } while (column1 <= column2 && overlap != true);
  }

  // check vertical
  if (column1 == column2) {
    do {
      if (field[row1][column1] == '#') {
        // Found overlap;
        overlap = true;
      }
      row1++;
    } while (row1 <= row2 && overlap != true);
  }

  return overlap;
}

// if there were no errors or overlap, function will be called to place ship
// onto a field
void Field::placeShip(ship s) {
  int row1 = charToInt(s.getrow1());
  int column1 = s.getcolumn1();
  int row2 = charToInt(s.getrow2());
  int column2 = s.getcolumn2();

  if (row1 == row2) {
    do {
      changeField(row1, column1, '#');
      column1++;
    } while (column1 <= column2);
  }

  if (column1 == column2) {
    do {
      changeField(row1, column1, '#');
      row1++;
    } while (row1 <= row2);
  }
}

Field Field::playerShot(Field copyField) // Player turn
{
  char tempX;
  int x;
  int y;

  bool newShot = false;
  // Hit p1;
  // Miss p_1;

  cout << "Which space would you like to shoot at?" << endl;

  while (newShot != true) {
    cin >> tempX;
    tempX = toupper(tempX);
    cin >> y;

    while (y > 10 || y < 1 || tempX < 'A' || tempX > 'J') // check
    {
      cin >> tempX;
      tempX = toupper(tempX);
      cin >> y;
    }

    cout << "\nShot fired at " << tempX << y << endl;

    // Reduce the y by one to account for the field array starting at 0, not 1
    y--;
    x = charToInt(tempX);
    x--;

    // Player checks - if hit or miss, choose new point
    if (field[x][y] == 'X' || field[x][y] == 'O') {
      cout << "Already fired there, enter a new location" << endl;
      newShot = false;
    }

    else if (field[x][y] == '#') // If hit, update copy to reflect player field
    {
      cout << "Hit" << endl;
      copyField.changeField(x + 1, y + 1, 'X');
      newShot = true;
    }

    else if (field[x][y] == ' ') // Miss
    {
      cout << "Miss" << endl;
      field[x][y] = 'O';
      copyField.changeField(x + 1, y + 1, 'O');

      // string xStr(1, tempX);
      newShot = true;
    }
  }

  return copyField; // Return updated copyField
}

// AI functions
// Ai shot
void Field::opponentShot() {
  int x;
  int y;
  bool newShot = false; // ai good to shoot in a spot
  string status;        // result of shot
  // Hit p2;
  // Miss p_2;

  while (newShot != true) {
    // creates a new coordinate
    x = rand() % 10;
    y = rand() % 10;

    // CPU cannot fire at a square already shot at
    if (field[x][y] == 'X' || field[x][y] == 'O') {
      newShot = false;
    }

    else if (field[x][y] == ' ') // If it's an empty spot, AI missed
    {
      // p_2.checkMiss(x, y, 'O');
      // field[x][y] = 'O';
      // status = "Miss";
      newShot = true;
    }

    else if (field[x][y] == '#') // if there was a ship there, AI hit
    {
      // p2.checkhit(x, y, 'X');
      // ield[x][y] = 'X';
      // status = "Hit";
      newShot = true;
    }
  }
  char tempX =
      intToChar(x + 1); // Convert coordinate to char so it can be displayed
  cout << "AI shoots at " << tempX << y + 1 << ". " << endl
       << status << "!!" << endl;
}
