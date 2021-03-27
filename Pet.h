/*
  ECS793P - INTRODUCTION TO OBJECT-ORIENTED PROGRAMMING - 2020/21

  Code Author: Luca Santarelli
  Student ID: 170385477
  Coursework: Pet Shop Individual Coursework
*/

// Header file for the Pet class, along its attributes and function declarations.
#include <string>
#pragma once
using namespace std;

class Pet {
  string type;
  int store_id;
  string pet_breed;
  int pet_age;
  string pet_colour;
  string country_origin;
  int price;

public:
  void setType(string type);
  void setID(int store_id);
  void setBreed(string pet_breed);
  void setAge(int pet_age);
  void setColour(string pet_colour);
  void setOrigin(string country_origin);
  void setPrice(int price);
  
  string getType();
  int getID();
  string getBreed();
  int getAge();
  string getColour();
  string getOrigin();
  int getPrice();
};
