/*
  ECS793P - INTRODUCTION TO OBJECT-ORIENTED PROGRAMMING - 2020/21

  Code Author: Luca Santarelli
  Student ID: 170385477
  Coursework: Pet Shop Individual Coursework
*/

// CPP file defining the functions of Pet class in the Pet.h file.
#include "Pet.h"
using namespace std;

// The below set functions are used to save attribute values to specific animals
// (i.e. Cat, Dog or Bird) from the base class Pet.
void Pet::setType(string type) {
  this->type = type;
}

void Pet::setID(int store_id) {
  this->store_id = store_id;
}

void Pet::setBreed(string pet_breed) {
  this->pet_breed = pet_breed;
}

void Pet::setAge(int pet_age) {
  this->pet_age = pet_age;
}

void Pet::setColour(string pet_colour) {
  this->pet_colour = pet_colour;
}

void Pet::setOrigin(string country_origin) {
  this->country_origin = country_origin;
}

void Pet::setPrice(int price) {
  this->price = price;
}

// The below get functions are used to get attribute values of specific animals
// (i.e. Cat, Dog or Bird) from the base class Pet.
string Pet::getType() { return type; }
int Pet::getID() { return store_id; }
string Pet::getBreed() { return pet_breed; }
int Pet::getAge() { return pet_age; }
string Pet::getColour() { return pet_colour; }
string Pet::getOrigin() { return country_origin; }
int Pet::getPrice() { return price; }
