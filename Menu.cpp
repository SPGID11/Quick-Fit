#include "Menu.h"
#include "Exercises.h"
#include <iostream> //to use cout and cin
#include <fstream>
#include "Tables.h"
#include "DLList.h"
#include <sstream>
using namespace std;

Exercises workouts;
Tables *tb;
int currentUser;
User retu;
Menu::Menu(){
  tb = new Tables();
  readUserDB("database.txt");
}

Menu::~Menu(){

}

void Menu::options(){
  welcome();
  retu = tb->getUser(currentUser);
  int options = -1;
  while(options != 7){
    cout << "          Welcome to QuickFit           " << endl;
    cout << "               Main Menu                " << endl;
    cout << "Enter the number corresponding with the action: " << endl;
    cout << "1. Start a workout" << endl;
    cout << "2. Update your experience" << endl;
    cout << "3. Update your focus" << endl;
    cout << "4. Update your Bench" << endl;
    cout << "5. Update your Squat" << endl;
    cout << "6. Update your Deadlift" << endl;
    cout << "7. Exit" << endl;
    cout << "Select an Option: " << endl;
    cin >> options;
    switch(options){
      case 1:
        //start a workout
        workout();
        break;
      case 2:
        //Update Experience
        updateExperience();
        break;
      case 3:
        //Update Focus
        updateFocus();
        break;
      case 4:
        //Update Focus
        updateBench();
        break;
      case 5:
        //Update Focus
        updateSquat();
        break;
      case 6:
        //Update Focus
        updateDeadlift();
        break;
      case 7:
        updateTable();
        cout << "Thank you for using QuickFit" << endl;
        break;
      case 8:
        tb->printUsersAscending();
        break;
      default:
        cout<< "Not a valid entry, try again" << endl;
      }
    }
}

void Menu::welcome(){
  string account;
  string username;
  string password;
  cout << "Welcome to Gainz!" << endl;
  cout << "Do you have an account? (yes/no)" << endl;
  cin >> account;
  if(account == "yes" || account == "Yes"){
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    cout << "  " << endl;
    loggedin(username, password);
  }
  else if (account == "no" || account == "No"){
    //create account
    cout << "Lets create an account" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    cout << "  " << endl;
    createAccount(username, password);
  }
  else{
    cout << "input is invalid try again" << endl;
  }
}

void Menu::loggedin(string username, string password){
  currentUser = tb->login(username, password);
}


void Menu::createAccount(string username, string password){
  string line;
  ofstream myfile; //("database.txt");
  int maxsid = tb->getMaxUserID() + 1; // increment by 1
  cout << "here" << endl;
  User u(maxsid,username,password,"none","none","-1","-1","-1");
  myfile.open("database.txt", ios::app);
  myfile << u;
  myfile.close();
  tb->addUser(u);
  currentUser = maxsid;
  cout << "Account succesfully created!" << endl;
}

void Menu::workout(){
  //workouts.dailyIndexScore();
  int choice;
  cout << "Select a workout for today (enter just the number corresponding to desired workout): " << endl;
  cout << "1. Push, 2. Pull, 3. Legs, 4. Arms, 5. Abs, 6. Glutes/Hamstrings" << endl;
  cin >> choice;
  switch (choice){
    case 1: workouts.push(retu.getBench());
    break;
    case 2: workouts.pull(retu.getDeadlift());
    break;
    case 3: workouts.legs(retu.getSquat());
    break;
    case 4: workouts.arms();
    break;
    case 5: workouts.abs();
    break;
    case 6: workouts.glutes_hammstrings();
    break;
    default: cout << "Invalid entry, try again." << endl;
  }
  workouts.toString(retu);
}

void Menu::updateExperience(){
  tb->alterExperience(currentUser);
}

void Menu::updateFocus(){
  tb->alterFocus(currentUser);
}

void Menu::updateBench(){
  tb->alterBench(currentUser);
}

void Menu:: updateSquat(){
  tb->alterSquat(currentUser);
}

void Menu::updateDeadlift(){
  tb->alterDeadlift(currentUser);
}

void Menu::readUserDB(string file){
  string goldFile = file;
  string line;
  ifstream userFile (goldFile);
  while ( getline (userFile,line) ) {
    string username;
    string password;
    string experience;
    string focus;
    string Bench;
    string Squat;
    string Deadlift;
    stringstream check1(line);
    string intermediate = "";
    DLList<string> tokens;

    // Tokenizing each field  '/' seperator
    while(getline(check1, intermediate, '/'))
    {
        tokens.insertBack(intermediate);
    }
    string userId_str = tokens.peek(0);
    stringstream userId(userId_str);
    int Id = atoi(userId_str.c_str());
    username = tokens.peek(1);
    password = tokens.peek(2);
    experience = tokens.peek(3);
    focus = tokens.peek(4);
    Bench = tokens.peek(5);
    Squat = tokens.peek(6);
    Deadlift = tokens.peek(7);

    User u(Id,username,password,experience,focus,Bench,Squat,Deadlift);
    tb->addUser(u);
  }
  userFile.close();
}

void Menu::updateTable(){
  string line;
  fstream myfile; //("database.txt");
  myfile.open("database.txt", ios::out);

  for(int i = 1; i < tb->getMaxUserID()+1;i++){
    myfile << tb->getUser(i);
  }
  myfile.close();
}
