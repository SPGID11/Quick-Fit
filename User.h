#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
using namespace std;

class User{
public:
  User();
  User(int id, string username, string password, string experience, string focus, string bench, string squat, string deadlift);
  ~User();
  int getUserID(); //returns user ID
  string getUsername(); //returns username
  void setUsername(string username); //changes username
  string getPassword(); //returns password
  void setPassword(string password); //changes password
  string getExperience(); //returns experience
  void setExperience(string experience); //changes experience
  string getFocus(); //returns focus
  void setFocus(string focus); //sets focus
  string getBench(); //gets time needed for a student at a window
  void setBench(string b); //sets the time needed for a student at a window
  string getSquat();
  void setSquat(string s);
  string getDeadlift();
  void setDeadlift(string d);


  //overloads less than operator (<) for student records to compare just id#s
  friend bool operator <(const User &s1, const User &s2){
    return (s1.UserID < s2.UserID);
  }

  //overloads greater than operator (>) for student records to compare just id#s
  friend bool operator >(const User &s1, const User &s2){
    return (s1.UserID > s2.UserID);
  }

  //overloads equal operator (==) for student records to compare just id#s
  friend bool operator ==(const User &s1, const User &s2){
    return (s1.UserID == s2.UserID);
  }

  //overloads not equal operator (!=) for student records to compare just id#s
  friend bool operator !=(const User &s1, const User &s2){
    return !(s1.UserID == s2.UserID);
  }

  //overloads cout operator (<<)  for a student record to display all attributes of the student record
  friend ostream& operator<<(ostream& os, const User &s1){
    os << s1.UserID << '/' << s1.username << '/' << s1.password << '/' << s1.experience << '/' << s1.focus << '/' << s1.bench << '/' << s1.squat << '/' << s1.deadlift;
    os << endl;
    return os;
  }
private:
  int UserID;
  string username;
  string password;
  string experience; //beginner, intermediate, advanced
  string focus; //strength/power/ muscle growth/
  string bench;
  string squat;
  string deadlift;
};

#endif
