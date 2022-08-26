#ifndef TABLES_H
#define TABLES_H
#include "User.h"
#include "BST.h"
#include <string>
using namespace std;

class Tables{
public:
  Tables(); //Default Constructor
  ~Tables(); //Destructor
  void addUser(User user); //Adds student records to student table
  void printUsersAscending();
  int getMaxUserID(); //returns max faculty record id
  int login(string username, string password);
  void alterExperience(int ID);
  void alterFocus(int ID);
  void alterBench(int ID);
  void alterSquat(int ID);
  void alterDeadlift(int ID);
  User getUser(int ID);

private:
  BST<User> UserTable; //table of user records
};

#endif
