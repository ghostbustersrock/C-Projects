/*
  ECS793P - INTRODUCTION TO OBJECT-ORIENTED PROGRAMMING - 2020/21

  Code Author: Luca Santarelli
  Student ID: 170385477
  Coursework: Pet Shop Individual Coursework
*/

// Header file for the Cat, Dog and Bird classes, along their attributes.
#include "Pet.h"
#pragma once

class Cat: public Pet {
public:
  string cat_neutered;
  string cat_vaccinated;
};

class Dog: public Pet {
public:
  string dog_neutered;
  string dog_vaccinated;
};

class Bird: public Pet {
public:
  string council_licenced;
};
