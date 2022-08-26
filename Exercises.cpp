#include "Exercises.h"
#include "Menu.h"
#include "User.h"
#include "Tables.h"
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <sstream>
#include <math.h>
using namespace std;


//defaullt constructor for a student
Exercises::Exercises(){
  workout = "";
  //string * exercises[6];
  exercises = new string[6];
}

//destructor
Exercises::~Exercises(){
}

//
void Exercises::arms(){
  string * tris = new string[2];
  string * bis = new string[2];
  string * shoulders = new string[2];
  workout = "Arm";
  //back exercises
  string tris_exercises [] = {"Skullcrushers: 12 reps", "NOTHING", "Tricep Extension (cables): 15 reps", "Tricep-Overhead Extension (cables): 20 reps", "Close-Grip Bench Press: 10 reps", "Bench Dip: 10 reps", "Dumbbell Overhead Triceps Extension: 12 reps", "Single-Arm Cable Kick-Back: 15 reps each arm", "Close-Grip Push-Up: 25 reps"};
  //bicep  exercises
  string bis_exercises [] = {"Barbell Curls: 10 reps", "NOTHING", "Bar Cable Curls: 10 reps", "EZ Bar Preacher Curls: 10 reps", "Incline Dumbbell Curls: 10 reps", "One arm Dumbbell Preacher Curls: 10 reps", "Reverse barbell curls: 10 reps", "Seated Dumbbell Curls: 10 reps", "Standing Biceps Cable Curl: 10 reps"};
  //shoulder exercises
  string shoulder_exercises[] = {"Lateral Raises: 10 reps", "NOTHING", "Front Raises: 10 reps", "Shoulder Press: 10 reps", "High Pull: 10 reps", "Farmer's Walk", "Dumbbell Neutral Grip Overhead Press: 10 reps", "Shrugs: 20 reps", "Upright Row: 10 reps"};
  int idx = 0;
  srand (time(NULL));
  while (idx != 2){
    int random = rand() % 9 + 0;
    int again = 0;
    for(int i = 0; i < 3; i++){
      if(tris[i] == tris_exercises[random] || random == 1){
        again = 1;
      }
    }
    if (again == 0){
      tris[idx] = tris_exercises[random];
      idx++;
    }
  }
  idx = 0;
  while (idx != 2){
    int random = rand() % 9 + 0;
    int again = 0;
    for(int i = 0; i < 2; i++){
      if(bis[i] == bis_exercises[random] || random == 1){
        again = 1;
      }
    }
    if (again == 0){
      bis[idx] = bis_exercises[random];
      idx++;
    }
  }
  idx = 0;
  while (idx != 2){
    int random = rand() % 9 + 0;
    int again = 0;
    for(int i = 0; i < 2; i++){
      if(shoulders[i] == shoulder_exercises[random] || random == 1){
        again = 1;
      }
    }
    if (again == 0){
      shoulders[idx] = shoulder_exercises[random];
      idx++;
    }
  }
  exercises[0] = tris[0];
  exercises[1] = bis[0];
  exercises[2] = shoulders[0];
  exercises[3] = tris[1];
  exercises[4] = bis[1];
  exercises[5] = shoulders[1];
}



void Exercises::abs(){
  string * abs = new string[5];
  string abs_exercises[] = {"Ab Wheel Rollout: 10 reps", "NOTHING" ,"Barbell Rollout: 15 reps", "Barbell Russian Twist: 30 reps", "Flutter Kick: 30 reps", "Leg Raise: 15 reps", "Medicine Ball Russian Twist: 15 reps", "Plank: 1 minute", "Pullup to Knee Raise: 15 reps", "Reverse Crunch: 15 reps", "Side Plank: 30 seconds each side", "Straight-Leg Barbell Situp: 12 reps", "Swiss Ball V-Up and Pass: 10 reps", "Sit-Ups: 20 reps", "Crunch: 15 reps", "Toe Touches: 20 reps"};
  int idx = 0;
  workout = "Ab";
  srand (time(NULL));
  while (idx !=5){
    int random = rand() % 16 + 0;
    int again = 0;
    for(int i = 0; i < 5; i++){
      if(abs[i] == abs_exercises[random] || random == 1){
        again = 1;
      }
    }
    if(again == 0){
      abs[idx] = abs_exercises[random];
      idx++;
    }
  }
  for(int i = 0; i < 5; i++){
    exercises[i] = abs[i];
  }
}

void Exercises::glutes_hammstrings(){
  string * glutes = new string[5];
  string glutes_exercises[] = {"Conventional Barbell Deadlift: 5-10 reps", "NOTHING", "Romanian Deadlift: 10 reps", "Trap Bar Deadlift: 10 reps", "Goodmornings: 10 reps", "Dumbbell RDL's: 10 reps each leg", "Back Raise: 10 reps", "Cable Pull Through: 10 reps each leg", "Kettle Bell Swings: 10 reps", "The Suit Case Deadlift: 10 reps"};
  int idx = 0;
  workout = "Leg Accesory";
  srand (time(NULL));
  while (idx !=5){
    int random = rand() % 10 + 0;
    int again = 0;
    for(int i = 0; i < 5; i++){
      if(glutes[i] == glutes_exercises[random] || random == 1){
        again = 1;
      }
    }
    if(again == 0){
      glutes[idx] = glutes_exercises[random];
      idx++;
    }
  }
  for(int i = 0; i < 5; i++){
    exercises[i] = glutes[i];
  }
}

void Exercises::legs(string squat){
  string * legs = new string[5];
  string legs_exercises[] = {"Squats", "NOTHING" ,"Back Squat: 5-10 reps", "Pause Squat: 5-10 reps", "Front Squat: 5-10 reps", "Box Squat: 5-10 reps", "Barbell Split Squat: 5-10 reps each leg", "The Goblet Squat: 10 reps", "Reverse Lunge: 5-10 reps each leg", "Bulgarian Split Squat: 5-10 reps each leg", "Step Ups: 5-10 reps each leg", "Pistols Thrusters: 5-10 reps each leg", "Wall Sits: 1 minute", "Leg Extensions: 12-20 reps", "Leg Curls: 10-15 reps", "RDL's: 10 reps"};
  int idx = 0;
  workout = "Leg";
  srand (time(NULL));
  while (idx !=5){
    int random_legs = rand() % 16 + 0;
    int again = 0;
    for(int i = 0; i < 5; i++){
      if(legs[i] == legs_exercises[random_legs] || random_legs == 1){
        again = 1;
      }
    }
    if(again == 0){
      legs[idx] = legs_exercises[random_legs];
      idx++;
    }
  }
  for(int i = 0; i < 5; i++){
    exercises[i] = legs[i];
  }
}

void Exercises::pull(string deadlift){
  string * back = new string[3];
  string * bi = new string[2];
  //back exercises
  string back_exercises [] = {"Deadlifts", "NOTHING", "Barbell Row: 10-12 reps", "Underhand EZ Bar Row: 10-12 reps", "Pull-ups/Chin-ups: 5-10 reps", "Power Cleans: 5-8 reps", "Lat Pulldowns: 10-12 reps", "Seated Cable Rows: 10 reps", "Dumbbell Rows: 8-12 reps each arm", "Face Pulls: 10-12 reps", "Chest Supported Rows: 8-10 reps"};
  //bicep  exercises
  string bi_exercises [] = {"Barbell Curls: 8-10 reps", "NOTHING", "Bar Cable Curls: 8-10 reps", "EZ Bar Preacher Curls: 8-10 reps", "Incline Dumbbell Curls: 8-10 reps", "One arm Dumbbell Preacher Curls: 8-10 reps each arm", "Reverse barbell curls: 8-10 reps", "Seated Dumbbell Curls: 5-10 reps each arm", "Standing Biceps Cable Curl: 8-10 reps"};
  int idx = 0;
  workout = "Pull";
  srand (time(NULL));
  while (idx != 3){
    int random = rand() % 11 + 0;
    int again = 0;
    for(int i = 0; i < 3; i++){
      if(back[i] == back_exercises[random] || random == 1){
        again = 1;
      }
    }
    if (again == 0){
      back[idx] = back_exercises[random];
      idx++;
    }
  }
  idx = 0;
  while (idx != 2){
    int random = rand() % 9 + 0;
    int again = 0;
    for(int i = 0; i < 2; i++){
      if(bi[i] == bi_exercises[random] || random == 1){
        again = 1;
      }
    }
    if (again == 0){
      bi[idx] = bi_exercises[random];
      idx++;
    }
  }
  exercises[0] = back[0];
  exercises[1] = bi[0];
  exercises[2] = back[1];
  exercises[3] = bi[1];
  exercises[4] = back[2];
}

//less than 1% chance of generating same workout
void Exercises::push(string bench){
  string * comp = new string[2];
  string * iso = new string[3];
  //compound push exercises
  string compound_push [] = {"Push-ups: 10-25 reps", "NOTHING", "Incline Bench Press: 5-10 reps", "Overhead Press: 8-12 reps", "Dumbbell Press: 5-10 reps", "Dumbbell Incline Press: 8-12 reps", "Bench Press", "Dips: 8-12 reps", "Shoulder Press: 8-12 reps"};
  //isometric push exercises
  string isometric_push [] = {"Tricep Extension: 10-15 reps", "NOTHING", "Chest Flys: 10-15 reps", "Lateral raises: 10 reps", "Overhead Tricep Extension: 10-20 reps"};
  //cout << sizeof(compound_push)/sizeof(compound_push[0]) << endl;
  int idx = 0;
  workout = "Push";
  srand (time(NULL));
  while (idx != 2){
    int random_comp = rand() %  7 + 0;
    int again = 0;
    for(int i = 0; i < 2; i++){
      //looking for repeats
      if(compound_push[random_comp] == comp[i] || random_comp == 1){
        again = 1;
      }
    }
    //no repeats
    if (again == 0){
      comp[idx] = compound_push[random_comp];
      idx++;
    }
  }
  int idx1 = 0;
  while (idx1 != 3){
    int random_iso = rand() %  5 + 0;
    int again = 0;
    for(int i = 0; i < 3; i++){
      if(isometric_push[random_iso] == iso[i] || random_iso == 1){
        again = 1;
      }
    }
    if (again == 0){
      iso[idx1] = isometric_push[random_iso];
      idx1++;
    }
  }
  exercises[0] = comp[0];
  exercises[1] = iso[0];
  exercises[2] = comp[1];
  exercises[3] = iso[1];
  exercises[4] = iso[2];
}

int Exercises::dailyIndexScore(){
  int hydration;
  int nutrition;
  int sleep;
  int stress;
  int energy;
  int idx;
  try{
    cout << "Answer the following questions 1-10: \n" << endl;
    cout << "1-3 poor, 4-5 below average, 6-7 average, 8-9 above average, 10 perfect" << endl;
    cout << "How hydrated are you?" << endl;
    cin >> hydration;
    cout << "How healthy was ur food or nutritional intake in the last 24 hrs?" << endl;
    cin >> nutrition;
    cout << "How much sleep did you get last night? " << endl;
    cin >> sleep;
    cout << "How stressed are you?" << endl;
    cin >> stress;
    cout << "How energized are you feeling?" << endl;
    cin >> energy;
  }
  catch(int e){
    cout << "Try entering valid data..." << endl;
  }
  IndexScore = float(hydration + nutrition + sleep + stress + energy)/50*100;
  cout << "Daily Index Score: " << IndexScore << "% \n" << endl;
  return IndexScore;
}

void Exercises::toString(User user){
  string sets;
  if(user.getExperience() == "advanced")
    sets = "5";
  else if(user.getExperience() == "intermediate")
    sets = "4";
  else if(user.getExperience() == "beginner")
    sets = "3";
  else{
    sets = "3";
  }
  int idx1 = dailyIndexScore();
  float idx = float(idx1);
  string reps;
  for(int i = 0; i < 5; i++){
    if(exercises[i] == "Bench Press" || exercises[i] == "Squats" || exercises[i] == "Deadlifts"){
      string reps_str;
      string weight_str;
      if(user.getFocus() == "strength"){
        reps_str = ", 3 reps";
      }
      if(user.getFocus() == "hypertrophy"){
        reps_str = ", 5 reps";
      }

      float weight;
      int pounds;
      if(workout == "Push"){
        string temp = user.getBench();
        stringstream userBench(user.getBench());
        int Bench = atoi(temp.c_str());
        weight = (Bench * (idx/100));
        pounds = (int)(roundf(weight / 5) * 5);
      }
      if (workout == "Pull"){
        string temp = user.getDeadlift();
        stringstream userDeadlift(user.getDeadlift());
        int Deadlift = atoi(temp.c_str());
        weight = (Deadlift * (idx/100));
        pounds = (int)(roundf(weight / 5) * 5);
      }
      if (workout == "Leg"){
        string temp = user.getSquat();
        stringstream userSquat(user.getSquat());
        int Squat = atoi(temp.c_str());
        weight = (Squat * (idx/100));
        pounds = (int)(roundf(weight / 5) * 5);
      }
      exercises[i] += ": ";
      exercises[i] += to_string(pounds);
      exercises[i] += "lbs";
      exercises[i] += reps_str;
    }
  }


  cout << workout << " Workout:" << endl;
  cout << sets << " sets" << endl;
  for(int i = 0; i < 5; i++){
    cout << exercises[i] << endl;
  }
}
