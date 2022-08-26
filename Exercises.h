#ifndef EXERCISES_H
#define EXERCISES_H

#include <string>
#include "User.h"
using namespace std;

class Exercises{
public:
  Exercises();
  ~Exercises();
  void arms();
  void abs();
  void glutes_hammstrings();
  void legs(string squat);
  void pull(string deadlift);
  void push(string bench);
  int dailyIndexScore();
  void toString(User u);
private:
  float IndexScore;
  string experience;
  string focus;
  int num;
  string workout;
  string * exercises;
};

#endif
