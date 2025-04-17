// Author: Samuel Chutter
// Date written: 11/25/2022
// Collaborators: Garrett Barney

#include <iomanip>

#include <iostream>

using namespace std;

class Robot { // declaring robot class
  int X;
  int Y;
  char lastCommand = 'x';
  int currentSpeed;
  int totalDistance;
  string name;

class RobotTrack {
  int locX;
  int locY;
  char NegOrPos;
  bool isOnAxis = true;
};

void locateRobot(char moverX, Robot *robotData){
  if(moverX==robotData->lastCommand){
    cout << "That is the correct answer." << endl;  
  }
}

public:
  Robot() { // constructor
    X = 0;
    Y = 0;
    currentSpeed = 1;
    totalDistance = 0;
  }

  string getName() // getter function
  {
  return name;
  }

  int getDistance() // getter function
  {
  return totalDistance;
  }  

  char getLastCommand() // getter function
  {
  return lastCommand;
  }

  void setName(string n) // getter function
  {
    name = n;
  }

  void moveRobot(char moverX, Robot *robotData, bool &s) { // this function is   responsible for moving the robots
    if (robotData->currentSpeed < 4 && moverX == robotData->lastCommand) {
      robotData->currentSpeed++;
    } else if (moverX != robotData->lastCommand) {
      robotData->currentSpeed = 1;
    } 
    if(s == true && (moverX == 's' || moverX == 'S'))
    { // checks to see if robot is stopped or started
      s = false; 
      cout << robotData -> name << " has started moving." << endl;
      robotData -> currentSpeed = 1;
    }
    else if(s==true && (moverX != 's' || moverX != 'S'))
    {
      cout << "Robot is stopped." << endl; // if stopped, deny move
    }
    else{
    switch (moverX) { // switch cases to determine which direction the bot moves

    case 'U':
    case 'u': // updating all directions in the robot pointers

      robotData->Y +=
          robotData->currentSpeed; // updates direction with amount of
      robotData->totalDistance +=
          robotData->currentSpeed; // moves based on speed

      break;

    case 'D':
    case 'd': // updating all directions in the robot pointers

      robotData->Y -= robotData->currentSpeed;
      robotData->totalDistance += robotData->currentSpeed;

      break;

    case 'L':
    case 'l': // updating all directions in the robot pointers

      robotData->X -= robotData->currentSpeed;
      robotData->totalDistance += robotData->currentSpeed;

      break;

    case 'R': 
    case 'r': // updating all directions in the robot pointers
 
      robotData->X += robotData->currentSpeed;
      robotData->totalDistance += robotData->currentSpeed;

      break;

    case 's': // turning on and off the robots
    case 'S': {
      if(s==true && (moverX=='s' || moverX=='S'))
      {
        s = false;
        cout << robotData -> name << " has started moving." << endl;
        robotData-> currentSpeed = 1;
      }
      else{ // checking to see if robot is moving or not
        s = true;
        cout << robotData -> name << " has stopped moving." << endl;
        robotData -> currentSpeed = 0;
      }
    }
    break;
      
    default:
      cout << "Invalid entry, enter a valid command." << endl;
    } // tells user to retry entry
  }

    cout << robotData->name
         << "'s position is "; // displays the robots position
    cout << robotData->X << ", ";
    cout << robotData->Y << endl;

    robotData->lastCommand = moverX;
  }

  Robot **makeRoboList(int numRobos) // function creates an array of robot pointers
  {
    Robot **roboPtrs = new Robot *[numRobos]; // double pointer points to the array

    cout << "Enter the names of the Robots." << endl;

    for (int i = 0; i < numRobos; i++) {
      roboPtrs[i] = new Robot;
    } // creates robot pointers

    for (int j = 0; j < numRobos; j++) {
      cin >> roboPtrs[j]->name;
    } // takes in name for each pointer

    return roboPtrs;
    delete [] roboPtrs; // garbage collection
  }

  int findRobot(int numRobots, Robot *robotData[], string nameRobot) // verifies names
  {
    for (int i = 0; i < numRobots; i++) {    // takes in names
      if (robotData[i]->name == nameRobot) { // for each robot
        return i;
      }
    }
    return -1; // false
  }

  };


  int main(int argc, char **argv) {

    char moverX;
    string nameRobot;
    int moveCount;
    char option; // variable declarations
    string newName;
    bool trueOrFalse;

    cout << "Welcome to the multi-robo mover." << endl;
    cout << "How many robots would you like to track?" << endl;

    int numRobots; // input users desired amounts of robots to track
    cin >> numRobots;

    //Robot **roboList = makeRoboList(numRobots); // creates the array of pointers

    Robot **roboList = Robot().makeRoboList(numRobots); // updates list of pointers
    // also calls constructor function
    
    cout << endl;
    cout << "Enter 'M or m' to move a robot." << endl;
    cout << "Enter 'R or r' to rename a robot." << endl;
    cout << "Enter 'D or d' to display the distance each robot has moved."
         << endl; // gives user options
    cout << "Enter 'U or u' to update RobotList" << endl;
    cout << "Enter 'Q or q' to quit the program" << endl;

    cin >> option; // takes in user option
    cout << endl;

    do {
      switch (option) { // switch case to determine what

      case 'M': // command user wants to do
      case 'm': {
        cout << "Enter robot name to move" << endl;
        cout << endl;
        string nameRobot;
        cin >> nameRobot;
        int robotIndex; 

        cout << "Enter the direction you want to move the robot." << endl;
        cout << "'U or u' to move up." << endl;
        cout << "'D or d' to move down." << endl;
        cout << "'R or r' to move right." << endl; // user options
        cout << "'L or l' to move left." << endl;
        cout << "'S or s' to stop or start moving."
             << endl; 

        char moverX;
        cin >> moverX;
        cout << endl;

        if (Robot().findRobot(numRobots, roboList, nameRobot) == -1) {
          option = -1; // checks to make sure its a valid name
          cout << "Invalid Robot Name" << endl;
        } else { // updates robot pointers
          robotIndex = Robot().findRobot(numRobots, roboList, nameRobot);
          Robot().moveRobot(moverX, roboList[robotIndex], trueOrFalse);
        }
        break;
      }

      case 'R':
      case 'r': // renames robots
        cout << "Enter the name of the robot you want to rename: " << endl;
        cin >> nameRobot;
        for(int i = 0; i < numRobots; i++){
          if(roboList[i] -> getName() == nameRobot){ // using getter to access name
            cout << "What do you want the new name to be?" << endl;
            cin >> nameRobot;
            roboList[i] -> setName(newName);
          }
        } // replaces name in each robot class

      case 'D': 
      case 'd': { // gets distances from getter function
        
        for (int i = 0; i < numRobots; i++) { // displays all robot's distances
          cout << roboList[i]->getName() << "  ";
          cout << roboList[i]->getDistance() << endl; // getter function call
        }
        break;
      }
      default:
        cout << endl << "Invalid entry; enter valid command." << endl;
        break;
      }

      cout << endl << "Enter another command: " << endl << "M - Move" << endl;
      cout << "D - Distance" << endl << "Q - Quit" << endl;
      cin >> option;
      cout << endl;
    } while (option != 'q' && option != 'Q'); // quits program

    cout << "Terminated, bye bye!" << endl;

    return 0;
  }
