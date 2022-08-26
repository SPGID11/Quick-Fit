#ifndef MENU_H
#define MENU_H

#include <string>
using namespace std;

class Menu{
public:
 Menu();
 ~Menu();
 void options();
 void welcome();
 void loggedin(string username, string password);
 void createAccount(string username, string password);
 void workout();
 void updateExperience();
 void updateFocus();
 void updateBench();
 void updateSquat();
 void updateDeadlift();

 void updateTable();
 void readUserDB(string file);
private:
};

#endif
