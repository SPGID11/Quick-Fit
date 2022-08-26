#include "User.h"

//defaullt constructor for a student
User::User(){
  username = "";
}

User::User(int id, string n, string p, string e, string f, string b, string s, string d){
  UserID = id;
  username = n;
  password = p;
  experience = e;
  focus = f;
  bench = b;
  squat = s;
  deadlift = d;
}

//destructor
User::~User(){
}

int User::getUserID(){
  return UserID;
}

string User::getUsername(){
  return username;
}

void User::setUsername(string name){
  username = name;
}

string User::getPassword(){
  return password;
}

void User::setPassword(string pas){
  password = pas;
}

string User::getExperience(){
  return experience;
}

void User::setExperience(string xp){
  experience = xp;
}

string User::getFocus(){
  return focus;
}

void User::setFocus(string foc){
  focus = foc;
}

//gets the users weight
string User::getBench(){
  return bench;
}

//sets the users wight
void User::setBench(string b){
  bench = b;
}

string User::getSquat(){
  return squat;
}

void User::setSquat(string s){
  squat = s;
}

string User::getDeadlift(){
  return deadlift;
}

void User::setDeadlift(string d){
  deadlift = d;
}
