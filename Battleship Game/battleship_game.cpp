/*
Battleship mini project, part 5.

Code by Luca Santarelli (student ID 170385477).
*/

#include <iostream>
#include <stdlib.h> //To use the system("clear") function.
#include <string> //To use strings.
using namespace std;

int playerNumb = 1; //To display the number of the player being entered.
int turn = 1; //Keeps track of the turn the game is at.
const int number_ships = 5; //For the for loop to enter the 5 ship's coordinates in addShips().
const int toWin = 17; //Total number of spaces occupied by the five ships

//This class deals with the main information of each ship.
class Ship {
public:
  int size;
  int hits;
  string shipType;

  Ship (int size, string shipType) {
    //Set ship size, type and hits (0 initially).
    this->size = size;
    this->shipType = shipType;
    hits = 0;
  }

  bool isSunk() {

  }

  int getSize() {

  }

  string getType() {

  }

  void hit() {

  }

}; //End of class Ship.

class BattleshipSquare {
public:
  Ship *ship;
  bool isFired;

  BattleshipSquare() {
    ship = NULL;
    isFired = false;
  }

  void reset() {
    ship = NULL;
  }

  bool addShip(Ship *ship) {

  }

  char getStatus() {

  }

  void fire() {

  }

}; //End of class BattleshipSquare.

//Class for anything related to the players boards.
class Board {
  public:
    int playerHit; //Keeping track of a player's successful hits.
    char spaces[8][8]; //Matrix to represent the board and place ships.
    char emptyBoard[8][8]; //Matrix used for the firing.
    BattleshipSquare squares[8][8];

    //Constructor to initialise the spaces and emptyBoard matrices.
    Board() {
      playerHit = 0;
      //Populating the placing ships and firing at ships board with nothing.
      for(int i = 0; i<8;i++) {
        for(int j = 0; j<8;j++) {
          spaces[i][j] = ' ';
          emptyBoard[i][j] = ' ';
        }
      }
    }

    //This resets the board so for the player to re-place its ships.
    void resetBoard() {
      for(int i = 0; i<8;i++) {
        for(int j = 0; j<8;j++) {
          spaces[i][j] = ' ';
        }
      }
      cout<<"Your board has been reset."<<endl;
    }

    //Function called when new ships placed on the board have to be shown.
    void displayPlacedBoard() {
      //Displaying the letters A to H on the board.
      char letter = 'A';
      cout<<"  | ";
      for (int i = 1; i <= 8; i++) {
        cout<<letter<<"  ";
        letter+=1; //To display the next letter board.
      }
      cout<<"\n--------------------------";
      cout<<endl;

      //Displaying the numbers 1 to 8 on the board.
      int number = 1;
      for (int i = 0; i<8; i++) {
        cout<<number<<" | ";

        for (int j = 0; j<8; j++) {
            //Displaying matrix with the 'S' or ' ' character to symbolize a ship or an empty space.
            cout<<spaces[i][j]<<"  ";
        }
        number+=1; //To display the next number on the board.
        cout<<endl;
      }
      return;
    }

    //Method to display the playing board of the players.
    void displayPlayBoard() {
      char letter = 'A';
      cout<<"  | ";
      for (int i = 1; i <= 8; i++) {
        cout<<letter<<"  ";
        letter+=1;
      }
      cout<<"\n--------------------------";
      cout<<endl;
      int number = 1;
      for (int i = 0; i<8; i++) {
        cout<<number<<" | ";

        for (int j = 0; j<8; j++) {
            //Printing the board to the shell.
            cout<<emptyBoard[i][j]<<"  ";
        }
        number+=1;
        cout<<endl;
      }
    }

    //Function to place the ships on the board and display current player's board if
    //valid coordinates for placement have been chosen.
    int placeShips(int xC, int yC, char direction, string shipName){
      int go = 0;
      if(shipName == "Carrier") {
        //Checking if the carrier ship doesn't exceed bounds or overlaps.
        go = squareState(xC, yC, direction, 5);
        if (go == 0) {
          //Error message for overlap or out of bounds coordinates choosing.
          cout<<"Invalid entry! Please try again."<<endl;
          return 0;
        }
      }
      else if(shipName == "Battleship") {
        //Checking if the battleship  doesn't exceed bounds or overlaps.
        go = squareState(xC, yC, direction, 4);
        if (go == 0) {
          //Error message for overlap or out of bounds coordinates choosing.
          cout<<"Invalid entry! Please try again."<<endl;
          return 0;
        }
      }
      else if(shipName == "Cruiser") {
        //Checking if the cruiser ship doesn't exceed bounds or overlaps.
        go = squareState(xC, yC, direction, 3);
        if (go == 0) {
          //Error message for overlap or out of bounds coordinates choosing.
          cout<<"Invalid entry! Please try again."<<endl;
          return 0;
        }
      }
      else if(shipName == "Submarine") {
        //Checking if the submarine ship doesn't exceed bounds or overlaps.
        go = squareState(xC, yC, direction, 3);
        if (go == 0) {
          //Error message for overlap or out of bounds coordinates choosing.
          cout<<"Invalid entry! Please try again."<<endl;
          return 0;
        }
      }
      else {
        //Checking if the destroyer ship doesn't exceed bounds or overlaps.
        go = squareState(xC, yC, direction, 2);
        if (go == 0) {
          //Error message for overlap or out of bounds coordinates choosing.
          cout<<"Invalid entry! Please try again."<<endl;
          return 0;
        }
      }

      cout<<"\x1B[2J\x1B[H"; //Clears the console's screen.
      //To disply the board with the correct chosen ship coordinates.
      displayPlacedBoard();
      cout<<endl;
      return 1;
    }

    //Checks if chosen coordinates don't exceed board bounds or overlap other ships.
    int squareState(int xC, int yC, char direction, int size) {
      int counter = 0; //To keep track of free spaces on the board.
      //Loop to count the number of free spaces available to place the ships, based on chosen direction.
      for(int z = 0; z<size; z++) {
        switch (direction) {
          //Check available spaces for north direction.
          case 'N':
          if (xC-z >= 0) {
            if(spaces[xC-z][yC] == ' ') {
              counter += 1;
            }
          }
          break;

          //Check available spaces for south direction.
          case 'S':
          if (xC+z < 8) {
            if(spaces[xC+z][yC] == ' ') {
              counter += 1;
            }
          }
          break;

          //Check available spaces for east direction.
          case 'E':
          if(yC+z < 8) {
            if(spaces[xC][yC+z] == ' ') {
              counter += 1;
            }
          }
          break;

          //Check available spaces for west direction.
          case 'W':
          if(yC-z >= 0) {
            if(spaces[xC][yC-z] == ' ') {
              counter += 1;
            }
          }
          break;
        }
      }//End for loop

      //Switch statement to either place ships if all spaces are available, otherwise
      //return zero to signal that an overlap or out of bound placement is occurring.
      switch (direction) {
        //For the north direction.
        case 'N':
        if (counter == size) {
          for (int i=0; i<size; i++) {
            spaces[xC-i][yC] = 'S';
          }
        }
        else {
          return 0; //Signal overlap or out of bound placement.
        }
        break;

        //For the south direction.
        case 'S':
        if (counter == size) {
          for (int i=0; i<size; i++) {
            spaces[xC+i][yC] = 'S';
          }
        }
        else {
          return 0; //Signal overlap or out of bound placement.
        }
        break;

        //For the east direction.
        case 'E':
        if (counter == size) {
          for (int i=0; i<size; i++) {
            spaces[xC][yC+i] = 'S';
          }
        }
        else {
          return 0; //Signal overlap or out of bound placement.
        }
        break;

        //For the west direction.
        case 'W':
        if (counter == size) {
          for (int i=0; i<size; i++) {
            spaces[xC][yC-i] = 'S';
          }
        }
        else {
          return 0; //Signal overlap or out of bound placement.
        }
        break;
      }
      return 1; //To exit the while loop in the addShips() and place the next ship.
    }

    //Function asking the x and y coordinates of the ships.
    void getCoordinates(char &x, char &y) {
      //Asking the player to enter the x coordinate.
      cout<<"Enter the x coordinate (A-H): ";
      cin>>y; //Saving the x coordinate.

      //If the x coordinate is beyond the A-H bound ask for the x coordinate again.
      while(y < 'A' || y > 'H') {
          cout<<"\nInvalid entry, please try again";
          cout<<"\nEnter the x coordinate (A-H): ";
          cin>>y;
      }

      //Asking the player to enter the y coordinate.
      cout<<"Enter the y coordinate (1-8): ";
      cin>>x; //Saving the y coordinate.

      //If the y coordinate is beyond the 1-8 bound ask for the y coordinate again.
      while(x > '8' || x < '1') {
          cout<<"\nInvalid entry, please try again";
          cout<<"\nEnter the y coordinate (1-8): ";
          cin>>x;
      }
      return;
    }

    //Checking if a ship has been hit or missed.
    int checkHit(int xC, int yC) {
      //If the fired coordinate has a ship print message and overwrite the matrix's spaces 'S'
      //with 'H' to show a ship has been hit.
      if (spaces[xC][yC] == 'S') {
        cout<<"It's a hit!"<<endl;
        emptyBoard[xC][yC] = 'H'; //The firstly empty matrix is now being populated with hits.
        spaces[xC][yC] = 'H'; //This will have print MISS afterwards if the same coordinate is called again.
                              //Implement the funtion that checks for duplicate coordinates.
        playerHit +=1; //Keeping track of the total spaces hit.
      }
      else {
        cout<<"It's a miss!"<<endl; //Print message in case of miss.
        emptyBoard[xC][yC] = 'M'; //The firstly empty matrix is now being populated with misses.
      }
      return playerHit;
    }

}; //End of class Board.

//Class for anything related to the players.
class Player {
  public:
    string playerName; //To save the player's name.
    Board board; //To access the Board class and its relative methods.
    Ship *ships[5];
    string shipNames[5] = {"Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer"};
    int sizeOfShips[5] = {5, 4, 3, 3, 2};
    //Arrays to save fired at coordinates (initially initialised with empty char: ' ').
    char usedX[64];
    char usedY[64];

    //Constructor to initialise the usedX and usedY arrays.
    Player() {
      for (int i = 0; i<64; i++) {
        usedX[i] = ' ';
        usedY[i] = ' ';
      }
    }

    //Function called to get the player's name.
    void getName() {
      //Asking the user for a player's name.
      cout<<"\x1B[2J\x1B[H";; //Clears the console's screen. Use "CLS" or "cls" for windows.

      cout<<"**Enter player "<<playerNumb<<" name: ";
      cin>>playerName;//getline(cin, playerName); //Saving the player's name.
      cout<<"\x1B[2J\x1B[H"; //Clears the console's screen.
      return;
    }

    //Function to clear the previous buffer and console.
    void enterToContinue() {
      cout<<"Press enter to continue!";
      cin.clear();
      cin.ignore(50,'\n'); //Clears the previous buffer.
      cin.get();
      cout<<"\x1B[2J\x1B[H";; //Clears the console's screen. Use "CLS" or "cls" for windows.
      return;
    }

    //Function to convert the inputted coordinates to valid ones for the board.
    void convertCoordinates(int &xC, int &yC, char x, char y) {
      for(int i = 0; i<8; i++) {
        if(y == (65 + i)) {
          yC = i;
        }
        if(x == (49 + i)) {
          xC = i;
        }
      }
    }

    //Function to add ships on the board.
    void addShips() {
      //Variables passed-by reference in the getCoordinates() function to get the
      //x and y coordinates and direction of the 5 ships to place on the board.
      char x, y, direction;
      string shipName[5] = {"Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer"};
      const int shipSize[5] = {5, 4, 3, 3, 2}; //Array with the sizes of the ships.
      //Displaying the menu of the ships to add.
      cout<<"\n---------------------------------"<<endl;
      cout<<"\t   Add Ships";
      cout<<"\n---------------------------------"<<endl;
      cout<<"     No  Name        Squares"<<endl;
      cout<<"---------------------------------"<<endl;
      cout<<"     1   Carrier        5"<<endl;
      cout<<"     1   Battleship     4"<<endl;
      cout<<"     1   Cruiser        3"<<endl;
      cout<<"     1   Submarine      3"<<endl;
      cout<<"     1   Destroyer      2"<<endl;
      cout<<endl;

      //Ask the user to add the coordinates of the 6 ships.
      for (int i = 0; i < number_ships; i++) {
        int proceed = 0;
        //Stays in the while loop till valid placements for ships have been chosen.
        //The program stays in the while loop if the user inputted coordinates that exceed the board's bound
        //or overlap another ship.
        while(proceed == 0) {
          cout<<"\n"<<playerName<<" add a "<<shipName[i]<< " of size: "<<shipSize[i]<<endl;
          //Getting the ships coordinates and saving them in x and y.
          board.getCoordinates(x, y);

          //Entering the directions the ships are placed.
          cout<<"Enter the direction (N/E/S/W): ";
          cin>>direction;

          //If an invalid direction has been place ask the player to re-enter it agian.
          while(direction != 'N' && direction != 'E' && direction != 'S' && direction != 'W') {
              cout<<"\nInvalid direction, please try again";
              cout<<"\nEnter the direction (N/E/S/W):  ";
              cin>>direction; //Saving the chosen direction.
          }

          //Converting the inputted coordinates to valid ones to be placed on the board.

          int xC, yC;
          //Function to convert the inputted coordinates to valid ones to be placed on the board.
          convertCoordinates(xC, yC, x, y);

          //Function to place the ships on the board, if valid coordinates have been chosen.
          proceed = board.placeShips(xC, yC, direction, shipName[i]);
        }//End main while loop.
      }//End for loop

      cout<<"\x1B[2J\x1B[H"; //Clears the console's screen.
      return;
    }

    //Function to check if the user has won.
    bool winLose(int hitsPlayer) {
      //Checking if the total spaces hit are the same as the number of places ships are in.
      if (hitsPlayer == toWin) {
        return true; //Return value to indicate victory.
      }
      else {
        return false; //Return value to stay in the while loop of the playerFire function because game not yet won.
      }
    }
}; //End of class Player.

//Function prototypes.
char displayMenu();
string startGame();
bool playerFire(Player &player1, Player &player2);

int main() {

  string playerWon; //To save name of the player who won.
  //Function to display the game's menu and return the user's choice.
  char selection = displayMenu();

  //If the user entered 1 (displayMenu() return value), call a function to start the game.
  if (selection == '1') {
      // cout<<"\x1B[2J\x1B[H"; //Clears the console's screen.
      playerWon = startGame(); //Function used to start the game.
  }
  //If the user entered 2, terminate the game with a goodbye message.
  else {
      cout<<"You have exited the game. Goodbye!"<<endl; //The goodbye message.
      return 0;
  }
  cout<<"Congratulations "<<playerWon<<" you have WON THE GAME!"<<endl;
  return 0; //End of the main() function, or end of game.
}

//Function used to display the main menu and return the user's menu selection.
char displayMenu() {
  //These first lines of code (with the cout) will display a menu to the user.
  cout<<"\n-----------------------------------------------------"<<endl;
  cout<<"\tHello and welcome to the main menu of..."<<endl;
  cout<<"\t\t     Battleships"<<endl;
  cout<<"-----------------------------------------------------"<<endl;
  cout<<"\t\t     1. Start Game"<<endl<<"\t\t     2. Exit Game"<<endl;

  char selection; //Variable to store user's menu choice.
  cout<<"\nChoose between 1 or 2: ";
  cin>>selection; //Saving the user's menu choice.

  //selection != 1 && selection != 2 || selection > '2' && selection < '1'
  //Loop entered if user chooses something different from 1 or 2.
  while(selection != '1' && selection != '2') {
      cout<<"Invalid entry, please try again."<<endl;
      //Asking the user for a choice again.
      cout<<"Choose between 1 or 2...";
      cin>> selection; //Saving the user's menu choice.
      cout<<endl;
  }
  return selection; //Returning the user's menu selection.
}

//Function to start the game.
string startGame() {
    char reset;
    //Creating two instances of the class Player.
    Player player1;
    Player player2;

    player1.getName(); //Getting and setting player 1 name.
    playerNumb += 1; //Increments the number of players playing the game.
    player2.getName(); //Getting and setting player 2 name.

    //The two players respectively add their ships to their boards.
    do {
      player1.addShips();
      cout<<"Do you wish to keep this board arrangement or reset it? (k/r)"<<endl;
      cin>>reset;
      while(reset != 'r' && reset != 'k') {
        cout<<"Please enter a valid input (k or r): ";
        cin>>reset;
      }
      if(reset == 'r') {
        cout<<"\x1B[2J\x1B[H";
        player1.board.resetBoard();
      }
    } while(reset != 'k');
    cout<<"\x1B[2J\x1B[H";

    do {
      player2.addShips();
      cout<<"Do you wish to keep this board arrangement or reset it? (k/r)"<<endl;
      cin>>reset;
      while(reset != 'r' && reset != 'k') {
        cout<<"Please enter a valid input (k or r): ";
        cin>>reset;
      }
      if(reset == 'r') {
        cout<<"\x1B[2J\x1B[H";
        player2.board.resetBoard();
      }
    } while(reset != 'k');
    cout<<"\x1B[2J\x1B[H";

    //Variables used to keep track of which player won.
    bool winPlayer1 = false;
    bool winPlayer2 = false;

    string playerWon; //To save the name of the player who won.
    //Loop for players to take turns to fire.
    while (winPlayer1 == false && winPlayer2 == false) {
      //Player 1 fires first and then checks if he/she won.
      winPlayer1 = playerFire(player1, player2);
      if (winPlayer1 == true) {
        //Return the player's 1 name in case of victory.
        playerWon = player1.playerName;
        break; //Exit while loop.
      }

      //Player 2 fires second and then checks if he/she won.
      winPlayer2 = playerFire(player2, player1);
      if (winPlayer2 == true) {
        //Return the player's 2 name in case of victory.
        playerWon = player2.playerName;
        break; //Exit while loop.
      }
    }
    return playerWon; //Return the winner's name.
}

//Function to choose coordinates to fire at.
bool playerFire(Player &player1, Player &player2) {
  int xC, yC;
  char x, y;

  cout<<"Turn: "<<turn<<"\n\n"; //Display the current turn.
  player2.board.displayPlayBoard(); //Function to display the player's board with H and M for hit and miss.

  cout<<"\n"<<player1.playerName<<" enter coordinates to fire."<<endl;
  cout<<"---------------------"<<endl;

  char duplicate; //Used to get our or stay in the do-while loop.
  int go; //To execute or not if-statement to save fired coordinates.
  //Do-while loop to check if the same set of coordinates haven't been inputted more than once.
  do {
    //Asking for firing coordinates to the user.
    player1.board.getCoordinates(x, y);
    //Checking if the chosen coordinates haven't been fired at already.
    for (int i = 0; i<64; i++) {
      if (player1.usedX[i] == x && player1.usedY[i] == y) {
        //Message to display in case coordinates have been chosen already.
        cout<<"Cannot input same coordinates more than once. Please try again.\n"<<endl;
        duplicate = 'T';
        go = 1;
        break;
      }
      else {
        go = 0;
        duplicate = 'F'; //To get out of the do-while loop.
      }
    }

    //If-statement accessed if go is zero, to save new fired coordinates.
    if (go == 0) {
      for(int i = 0; i<64; i++) {
        if(player1.usedX[i] == ' ' && player1.usedY[i] == ' ') {
          player1.usedX[i] = x;
          player1.usedY[i] = y;
          break;
        }
      }
    }

  } while(duplicate == 'T');

  //Converting new inputted coordinates to valid ones to be placed on the board.
  player1.convertCoordinates(xC, yC, x, y);
  //Function called to check if the fired at coordinate has a ship or not.
  int hits = player2.board.checkHit(xC, yC);

  //Function checking if the current player has won.
  bool win = player1.winLose(hits);
  player1.enterToContinue(); //Function to clear the previous buffer and console.
  cout<<endl;
  turn +=1; //Increasing the turn count, after the end of each firing.

  return win; //Returning 'T' or 'F' to indicate if the current player has won or not.
}
