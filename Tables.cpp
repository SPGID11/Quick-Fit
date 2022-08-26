#include "Tables.h"
using namespace std;

//Default Constructor
Tables::Tables(){
    //studentTable = new BST<StudentRecords>;
}

//Destructor
Tables::~Tables(){

}

//Adds student records to student table
void Tables::addUser(User user){
  UserTable.insert(user);
}

void Tables::printUsersAscending(){
  UserTable.printInOrder();
}

//returns max student record id
int Tables::getMaxUserID(){
  User rets = UserTable.getMax();
  return rets.getUserID();
}

//Finds faculty record in faculty table and displays attributes of given faculty given an int id
int Tables::login(string username, string password) {
  int id = -1;
  for(int i = 0; i < getMaxUserID(); i++){
    User retu = getUser(i);
    if (retu.getUsername() == username && retu.getPassword() == password){
      id = retu.getUserID();
      cout << "Welcome, " << retu.getUsername() << endl;
      break;
    }
  }
  if (id == -1)
    cout << " USER NOT FOUND...." << endl;
  return id;
}

void Tables::alterExperience(int ID){
  User u1 = User(ID,"","","","","","","");
  User retu = UserTable.returnRecord(u1);
  string choice;
  string experience;
  cout << "Current experience: " << retu.getExperience() << endl;
  cout << "Would you like to update your experience? (yes/no)" << endl;
  cin >> choice;
  if (choice == "yes" || choice == "Yes"){
    char xp;
    cout << "Select a level: 1 (beginner),  2 (intermediate), 3 (advanced)";
    cin >> xp;
    switch (xp) {
      case '1': experience = "beginner";
      break;
      case '2': experience = "intermediate";
      break;
      case '3': experience = "advanced";
      break;
      default: cout << "Invalid input" << endl;
    }
    retu.setExperience(experience);
  }
  UserTable.deleteValue(u1);
  UserTable.insert(retu);
}

void Tables::alterFocus(int ID){
  User u1 = User(ID,"","","","","","","");
  User retu = UserTable.returnRecord(u1);
  string choice;
  string focus;
  cout << "Current focus: " << retu.getFocus() << endl;
  cout << "Would you like to update your focus? (yes/no)" << endl;
  cin >> choice;
  if (choice == "yes" || choice == "Yes"){
    char xp;
    cout << "Select a level: 1 (strength),  2 (hypertrophy)";
    cin >> xp;
    switch (xp) {
      case '1': focus = "strength";
      break;
      case '2': focus = "hypertrophy";
      break;
      default: cout << "Invalid input" << endl;
    }
    retu.setFocus(focus);
  }
  UserTable.deleteValue(u1);
  UserTable.insert(retu);
}

void Tables::alterBench(int ID){
  User u1 = User(ID,"","","","","","","");
  User retu = UserTable.returnRecord(u1);
  string choice;
  string bench;
  cout << "Current bench: " << retu.getBench() << endl;
  cout << "Would you like to update your Bench? (yes/no)" << endl;
  cin >> choice;
  if (choice == "yes" || choice == "Yes"){
    cout << "How much can you bench for 1rm?" << endl;
    cin >> bench;
    retu.setBench(bench);
  }
  UserTable.deleteValue(u1);
  UserTable.insert(retu);
}

void Tables::alterSquat(int ID){
  User u1 = User(ID,"","","","","","","");
  User retu = UserTable.returnRecord(u1);
  string choice;
  string squat;
  cout << "Current squat: " << retu.getSquat() << endl;
  cout << "Would you like to update your squat? (yes/no)" << endl;
  cin >> choice;
  if (choice == "yes" || choice == "Yes"){
    cout << "How much can you squat for 1rm?" << endl;
    cin >> squat;
    retu.setSquat(squat);
  }
  UserTable.deleteValue(u1);
  UserTable.insert(retu);
}

void Tables::alterDeadlift(int ID){
  User u1 = User(ID,"","","","","","","");
  User retu = UserTable.returnRecord(u1);
  string choice;
  string deadlift;
  cout << "Current deadlift: " << retu.getDeadlift() << endl;
  cout << "Would you like to update your deadlift? (yes/no)" << endl;
  cin >> choice;
  if (choice == "yes" || choice == "Yes"){
    cout << "How much can you deadlift for 1rm?" << endl;
    cin >> deadlift;
    retu.setDeadlift(deadlift);
  }
  UserTable.deleteValue(u1);
  UserTable.insert(retu);
}

User Tables::getUser(int ID){
  User u1 = User(ID,"","","","","","","");
  User retu = UserTable.returnRecord(u1);
  return retu;
}
