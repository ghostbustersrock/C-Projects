/*
  ECS793P - INTRODUCTION TO OBJECT-ORIENTED PROGRAMMING - 2020/21

  Code Author: Luca Santarelli
  Student ID: 170385477
  Coursework: Pet Shop Individual Coursework
*/

// Libraries and header files used for the program.
#include "Pet.h" // To include the Pet class.
#include "SubPets.h" // To include the Cat, Dog and Bird classes.
#include <iostream>
#include <fstream>
#include <vector>
#include <ctype.h>
using namespace std;

int size = 9; // Size of the array to temporarirly store file values in.

void printCats(vector<Cat*> cat, int i) { // Function to print specific cats.
  cout<<cat[i]->getType()<<endl;
  cout<<cat[i]->getID()<<endl;
  cout<<cat[i]->getBreed()<<endl;
  cout<<cat[i]->getAge()<<endl;
  cout<<cat[i]->getColour()<<endl;
  cout<<cat[i]->getOrigin()<<endl;
  cout<<cat[i]->getPrice()<<endl;
  cout<<cat[i]->cat_neutered<<endl;
  cout<<cat[i]->cat_vaccinated<<endl;
  cout<<endl;
}

void printDogs(vector<Dog*> dog, int i) { // Function to print specific dogs.
  cout<<dog[i]->getType()<<endl;
  cout<<dog[i]->getID()<<endl;
  cout<<dog[i]->getBreed()<<endl;
  cout<<dog[i]->getAge()<<endl;
  cout<<dog[i]->getColour()<<endl;
  cout<<dog[i]->getOrigin()<<endl;
  cout<<dog[i]->getPrice()<<endl;
  cout<<dog[i]->dog_neutered<<endl;
  cout<<dog[i]->dog_vaccinated<<endl;
  cout<<endl;
}

void printBirds(vector<Bird*> bird, int i) { // Function to print specific birds.
  cout<<bird[i]->getType()<<endl;
  cout<<bird[i]->getID()<<endl;
  cout<<bird[i]->getBreed()<<endl;
  cout<<bird[i]->getAge()<<endl;
  cout<<bird[i]->getColour()<<endl;
  cout<<bird[i]->getOrigin()<<endl;
  cout<<bird[i]->getPrice()<<endl;
  cout<<bird[i]->council_licenced<<endl;
  cout<<endl;
}

// Function checking if the inputted values of new Pet's attributes to save are valid.
void checkValue(string &value, string msg, string err_msg, int choice, int num1, int num2) {
  bool flag = true;
  cout<<msg; // Message stating the attribute to save.
  getline(cin, value);

  /*
    Switch statement used to perform different while loops with inner for loops and
    if statements to saved valid values for specific attributes.
  */
  switch (choice) {
    case 1: // Checks for inputs which should not contain numbers.
      while(flag) {
        for(int i=0; i<value.length(); i++){
          if(isdigit(value[i]) != 0) {
            cout<<err_msg; // Display possible error message if input is not valid.
            getline(cin, value);
            flag = true;
            break;
          }
          else {
            flag = false;
          }
        }
      }
    break;

    case 2: // Checks for inputs which should contain numbers.
      while(flag) {
        for(int i=0; i<value.length(); i++){
          if(isdigit(value[i]) == 0) {
            cout<<err_msg; // Display possible error message if input is not valid.
            getline(cin, value);
            flag = true;
            break;
          }
          else {
            flag = false;
          }
        }
      }
    break;

    case 3: // Checks for numerical inputs relative to the ID and price range of a pet.
      while(flag) {
        for(int i=0; i<value.length(); i++) {
          if(isdigit(value[i]) == 0) {
            cout<<err_msg; // Display possible error message if input is not valid.
            getline(cin, value);
            flag = true;
            break;
          }
          else {
            flag = false;
          }
        }
        if (flag == false) {
          // Checks if valid inputted numerical values are valid ID and price ranges.
          if (stoi(value) < num1 || stoi(value) > num2) {
            cout<<err_msg;
            getline(cin, value);
            flag = true;
          }
          else {
            flag = false;
          }
        }
      }
    break;

    default: // Checks for inputs relative to the neutered and vaccinated status of a pet.
      while(value != "YES" && value != "NO") {
        cout<<err_msg; // Display possible error message if input is not valid.
        getline(cin, value);
      }
    break;
  }
}

// Function to add cat values to the Pet and Cat class attributes.
void addCat(vector<Cat*> &cat, string animal) {
  string string_values;
  cat.push_back(new Cat()); // Creating a new cat object.
  // Saving the type of the animal to the 'type' attribute of the Pet class.
  cat.back()->setType(animal);

  cin.clear();
  cin.ignore(50, '\n');
  // Saving the inputted cat ID to the ID attribute of the Pet class.
  string msg = "Insert the cat's ID (1000 - 2000): ";
  string err_msg = "Invalid ID. Please insert a valid ID (1000 - 2000): ";
  checkValue(string_values, msg, err_msg, 3, 1000, 2000); // Checking if the inputted value is valid.
  cat.back()->setID(stoi(string_values));

  // Saving the inputted cat breed to the breed attribute of the Pet class.
  msg = "Insert the cat's breed: ";
  err_msg = "Invalid breed. Please insert a valid breed: ";
  checkValue(string_values, msg, err_msg, 1, 0, 0); // Checking if the inputted value is valid.
  cat.back()->setBreed(string_values);

  // Saving the inputted cat age to the age attribute of the Pet class.
  msg = "Insert the cat's age: ";
  err_msg = "Invalid age. Please insert a valid age: ";
  checkValue(string_values, msg, err_msg, 2, 0, 0); // Checking if the inputted value is valid.
  cat.back()->setAge(stoi(string_values));

  // Saving the inputted cat colour(s) to the colour(s) attribute of the Pet class.
  msg = "Insert the cat's colour(s): ";
  err_msg = "Invalid colour(s). Please insert valid colour(s): ";
  checkValue(string_values, msg, err_msg, 1, 0, 0); // Checking if the inputted value is valid.
  cat.back()->setColour(string_values);

  // Saving the inputted cat origin to the country_origin attribute of the Pet class.
  msg = "Insert the cat's country of origin: ";
  err_msg = "Invalid country of origin. Please insert a valid country of origin: ";
  checkValue(string_values, msg, err_msg, 1, 0, 0); // Checking if the inputted value is valid.
  cat.back()->setOrigin(string_values);

  // Saving the inputted cat price to the price attribute of the Pet class.
  msg = "Insert the cat's price (£1 - £100): £";
  err_msg = "Invalid price. Please insert a price between £1 - £100: £";
  checkValue(string_values, msg, err_msg, 3, 1, 100); // Checking if the inputted value is valid.
  cat.back()->setPrice(stoi(string_values));

  // Saving the inputted cat neutered status to the cat_neutered attribute of the Cat class.
  msg = "Has the cat been neutered? (YES/NO): ";
  err_msg = "Invalid input. Please insert YES or NO for neutered status: ";
  checkValue(string_values, msg, err_msg, 4, 0, 0); // Checking if the inputted value is valid.
  cat.back()->cat_neutered = string_values;

  // Saving the inputted cat vaccinated status to the cat_vaccinated attribute of the Cat class.
  msg = "Has the cat been vaccinated? (YES/NO): ";
  err_msg = "Invalid input. Please insert YES or NO for vaccinated status: ";
  checkValue(string_values, msg, err_msg, 4, 0, 0); // Checking if the inputted value is valid.
  cat.back()->cat_vaccinated = string_values;

  cout<<"\n\nYou have SUCCESSFULLY added a new cat to the inventory"<<endl;
}

// Function to add dog values to the Pet and Dog class attributes.
void addDog(vector<Dog*> &dog, string animal) {
  string string_values;
  dog.push_back(new Dog()); // Creating a new Dog object.
  // Saving the type of the animal to the 'type' attribute of the Pet class.
  dog.back()->setType(animal);

  cin.clear();
  cin.ignore(50, '\n');
  // Saving the inputted dog ID to the ID attribute of the Pet class.
  string msg = "Insert the dog's ID (1000 - 2000): ";
  string err_msg = "Invalid ID. Please insert a valid ID (1000 - 2000): ";
  checkValue(string_values, msg, err_msg, 3, 1000, 2000); // Checking if the inputted value is valid.
  dog.back()->setID(stoi(string_values));

  // Saving the inputted dog breed to the breed attribute of the Pet class.
  msg = "Insert the dog's breed: ";
  err_msg = "Invalid breed. Please insert a valid breed: ";
  checkValue(string_values, msg, err_msg, 1, 0, 0); // Checking if the inputted value is valid.
  dog.back()->setBreed(string_values);

  // Saving the inputted dog age to the age attribute of the Pet class.
  msg = "Insert the dog's age: ";
  err_msg = "Invalid age. Please insert a valid age: ";
  checkValue(string_values, msg, err_msg, 2, 0, 0); // Checking if the inputted value is valid.
  dog.back()->setAge(stoi(string_values));

  // Saving the inputted dog colour(s) to the colour(s) attribute of the Pet class.
  msg = "Insert the dog's colour(s): ";
  err_msg = "Invalid colour(s). Please insert valid colour(s): ";
  checkValue(string_values, msg, err_msg, 1, 0, 0); // Checking if the inputted value is valid.
  dog.back()->setColour(string_values);

  // Saving the inputted dog origin to the country_origin attribute of the Pet class.
  msg = "Insert the dog's country of origin: ";
  err_msg = "Invalid country of origin. Please insert a valid country of origin: ";
  checkValue(string_values, msg, err_msg, 1, 0, 0); // Checking if the inputted value is valid.
  dog.back()->setOrigin(string_values);

  // Saving the inputted dog price to the price attribute of the Pet class.
  msg = "Insert the dog's price (£1 - £100): £";
  err_msg = "Invalid price. Please insert a price between £1 - £100: £";
  checkValue(string_values, msg, err_msg, 3, 1, 100); // Checking if the inputted value is valid.
  dog.back()->setPrice(stoi(string_values));

  // Saving the inputted dog neutered status to the dog_neutered attribute of the Cat class.
  msg = "Has the dog been neutered? (YES/NO): ";
  err_msg = "Invalid input. Please insert YES or NO for neutered status: ";
  checkValue(string_values, msg, err_msg, 4, 0, 0); // Checking if the inputted value is valid.
  dog.back()->dog_neutered = string_values;

  // Saving the inputted dog vaccinated status to the dog_vaccinated attribute of the Cat class.
  msg = "Has the dog been vaccinated? (YES/NO): ";
  err_msg = "Invalid input. Please insert YES or NO for vaccinated status: ";
  checkValue(string_values, msg, err_msg, 4, 0, 0); // Checking if the inputted value is valid.
  dog.back()->dog_vaccinated = string_values;

  cout<<"\n\nYou have SUCCESSFULLY added a new dog to the inventory"<<endl;
}

// Function to add bird values to the Pet and Bird class attributes.
void addBird(vector<Bird*> &bird, string animal) {
  string string_values;
  bird.push_back(new Bird()); // Creating a new Bird object.
  // Saving the type of the animal to the 'type' attribute of the Pet class.
  bird.back()->setType(animal);

  cin.clear();
  cin.ignore(50, '\n');
  string msg = "Insert the bird's ID (1000 - 2000): ";
  string err_msg = "Invalid ID. Please insert a valid ID (1000 - 2000): ";
  checkValue(string_values, msg, err_msg, 3, 1000, 2000); // Checking if the inputted value is valid.
  bird.back()->setID(stoi(string_values));

  // Saving the inputted bird ID to the ID attribute of the Pet class.
  msg = "Insert the bird's breed: ";
  err_msg = "Invalid breed. Please insert a valid breed: ";
  checkValue(string_values, msg, err_msg, 1, 0, 0); // Checking if the inputted value is valid.
  bird.back()->setBreed(string_values);

  // Saving the inputted bird age to the age attribute of the Pet class.
  msg = "Insert the bird's age: ";
  err_msg = "Invalid age. Please insert a valid age: ";
  checkValue(string_values, msg, err_msg, 2, 0, 0); // Checking if the inputted value is valid.
  bird.back()->setAge(stoi(string_values));

  // Saving the inputted bird colour(s) to the pet_colour attribute of the Pet class.
  msg = "Insert the bird's colour(s): ";
  err_msg = "Invalid colour(s). Please insert valid colour(s): ";
  checkValue(string_values, msg, err_msg, 1, 0, 0); // Checking if the inputted value is valid.
  bird.back()->setColour(string_values);

  // Saving the inputted bird origin to the country_origin attribute of the Pet class.
  msg = "Insert the bird's country of origin: ";
  err_msg = "Invalid country of origin. Please insert a valid country of origin: ";
  checkValue(string_values, msg, err_msg, 1, 0, 0); // Checking if the inputted value is valid.
  bird.back()->setOrigin(string_values);

  // Saving the inputted bird price to the price attribute of the Pet class.
  msg = "Insert the bird's price (£1 - £100): £";
  err_msg = "Invalid price. Please insert a price between £1 - £100: £";
  checkValue(string_values, msg, err_msg, 3, 1, 100); // Checking if the inputted value is valid.
  bird.back()->setPrice(stoi(string_values));

  // Saving the inputted bird council licence status to the council_licenced attribute of the Bird class.
  msg = "Is the council licenced? (YES/NO): ";
  err_msg = "Invalid input. Please insert YES or NO for licence status: ";
  checkValue(string_values, msg, err_msg, 4, 0, 0); // Checking if the inputted value is valid.
  bird.back()->council_licenced = string_values;

  cout<<"\n\nYou have SUCCESSFULLY added a new bird to the inventory"<<endl;
}

// Reading initial values of cats, dogs and birds from a file and checking if the file
// can be opened.
bool createAnimal(vector<Cat*> &cat, vector<Dog*> &dog, vector<Bird*> &bird) {

  string array[9] = {"","","","","","","","","",}; // Array to store each pet's value in.
  string firstElement; // To store the type of pet to save.
  ifstream inputFile("petsInventory.txt"); //Open a file to read its contents.

  if (inputFile.is_open()) { // Checking if the file can be opened.
    //Read the file's content till its end has been reached.
    while(inputFile.eof() != true) {
      getline(inputFile, firstElement);

      // Checking if the first line of the set of values of the file is a Cat or Dog.
      if (firstElement == "Cat" || firstElement == "Dog") {
        // Reading each value of the pet cat or dog.
        for(int j = 0; j<size-1; j++) {
          getline(inputFile, array[j]);
        }
        // If the set of values is for cats create a new cat vector object
        // and store the values in there.
        if (firstElement == "Cat") {
          cat.push_back(new Cat());
          cat.back()->setType(firstElement);
          cat.back()->setID(stoi(array[0]));
          cat.back()->setBreed(array[1]);
          cat.back()->setAge(stoi(array[2]));
          cat.back()->setColour(array[3]);
          cat.back()->setOrigin(array[4]);
          cat.back()->setPrice(stoi(array[5]));
          cat.back()->cat_neutered = array[6];
          cat.back()->cat_vaccinated = array[7];
        }

        // If the set of values is for dogs create a new dog vector object
        // and store the values in there.
        else {
          dog.push_back(new Dog());
          dog.back()->setType(firstElement);
          dog.back()->setID(stoi(array[0]));
          dog.back()->setBreed(array[1]);
          dog.back()->setAge(stoi(array[2]));
          dog.back()->setColour(array[3]);
          dog.back()->setOrigin(array[4]);
          dog.back()->setPrice(stoi(array[5]));
          dog.back()->dog_neutered = array[6];
          dog.back()->dog_vaccinated = array[7];
        }
      }

      // Checking if the first line of the set of values of the file is a Cat or Dog.
      if (firstElement == "Bird") {
        for(int j = 0; j<size-2; j++) {
          getline(inputFile, array[j]);
        }
        // If the set of values is for birds create a new bird vector object
        // and store the values in there.
        bird.push_back(new Bird());
        bird.back()->setType(firstElement);
        bird.back()->setID(stoi(array[0]));
        bird.back()->setBreed(array[1]);
        bird.back()->setAge(stoi(array[2]));
        bird.back()->setColour(array[3]);
        bird.back()->setOrigin(array[4]);
        bird.back()->setPrice(stoi(array[5]));
        bird.back()->council_licenced = array[6];
      }

      for(int i = 0; i<size; i++) {
        array[i] = ""; // Reset array to hold pets values to empty.
      }
    }
  }
  else { // Return false if file cannot be opened.
    return false;
  }

  inputFile.close(); // Closing the recently opened file.
  return true; // Return true if file can be opened.
}

void mainMenu(string &option) { // To display the store's menu and select something from it.
  cout<<"Select a number for one of the options below:\n";
  cout<<"1) Pet Inventory.\n2) Exit Inventory.\n\nChosen option: ";
  getline(cin, option);

  bool flag = true;
  //Stay in the while loop until a correct input has been given.
  while(flag) {
    for(int i=0; i<option.length(); i++){ // Checking if the given input is only numbers.
      if(isdigit(option[i]) == 0) {
        cout<<"\x1B[2J\x1B[H";
        cout<<"Invalid ID! Select a number for one of the options below:\n"; // Display error message if input is not valid.
        cout<<"1) Pet Inventory.\n2) Exit Inventory.\n\nChosen option: ";
        getline(cin, option);
        flag = true;
        break;
      }
      else {
        flag = false;
      }
    }
    if (flag == false) {
      if (stoi(option) != 1 && stoi(option) != 2) { // Check if the input is 1 or 2.
        cout<<"\x1B[2J\x1B[H";
        cout<<"Invalid ID! Select a number for one of the options below:\n"; // Display error message if input is not valid.
        cout<<"1) Pet Inventory.\n2) Exit Inventory.\n\nChosen option: ";
        getline(cin, option);
        flag = true;
      }
      else {
        break; // Exit while loop if input is only numbers and in the valid range.
      }
    }
  }
}

void secondaryMenu(string &option) { // To display further options to do.
  cout<<"\t\tPlease select what you wish to do\n\n";
  cout<<"Search pet by:\n  1) Type and store ID and/or price range\n  2) Details";
  cout<<"\n\nOther options:\n  3) Display all pets\n  4) Exit Pet Shop Inventory\n\n";
  cout<<"Chosen option: ";
  getline(cin, option);

  bool flag = true;
  //Stay in the while loop until a correct input has been given.
  while(flag) {
    for(int i=0; i<option.length(); i++){ // Checking if the given input is only numbers.
      if(isdigit(option[i]) == 0) {
        cout<<"\x1B[2J\x1B[H";
        cout<<"\t\tInvalid input! Please select what you wish to do\n\n"; // Display error message if input is not valid.
        cout<<"Search pet by:\n  1) Type and store ID and/or price range\n  2) Details";
        cout<<"\n\nOther options:\n  3) Display all pets\n  4) Exit Pet Shop Inventory\n\n";
        cout<<"Chosen option: ";
        getline(cin, option);
        flag = true;
        break;
      }
      else {
        flag = false;
      }
    }
    if (flag == false) {
      // Check if the input is 1, 2, 3 or 4.
      if (stoi(option) != 1 && stoi(option) != 2 && stoi(option) != 3 && stoi(option) != 4) {
        cout<<"\x1B[2J\x1B[H";
        cout<<"\t\tInvalid input! Please select what you wish to do\n\n"; // Display error message if input is not valid.
        cout<<"Search pet by:\n  1) Type and store ID and/or price range\n  2) Details";
        cout<<"\n\nOther options:\n  3) Display all pets\n  4) Exit Pet Shop Inventory\n\n";
        cout<<"Chosen option: ";
        getline(cin, option);
        flag = true;
      }
      else {
        break; // Exit while loop if input is only numbers and in the valid range.
      }
    }
  }
}

void searchByType(string &animal) { // Asking what type of animal to search for.
  cout<<"\x1B[2J\x1B[H";
  cout<<"What type of animal Do you want to search for?"<<endl;
  cout<<"- Cat\n- Dog\n- Bird\n\n";
  cout<<"Option: ";
  cin>>animal;
  cout<<endl;

  //Stay in the while loop until a correct input has been given.
  while (animal != "Cat" && animal != "Dog" && animal != "Bird") {
    cout<<"\x1B[2J\x1B[H";
    cout<<"\nSorry there's no such animal! What type of animal Do you want to search for?"<<endl;
    cout<<"- Cat\n- Dog\n- Bird\n\n";
    cout<<"Option: ";
    cin>>animal;
    cout<<endl;
  }
}

int searchByID(string animal) { // Asking which ID to search for.
  string id;
  bool flag = true;
  cin.clear();
  cin.ignore(50, '\n');
  cout<<"\x1B[2J\x1B[H";
  cout<<"What is the "<<animal<<"'s ID you want to search for? (1000 - 2000)"<<endl;
  cout<<"Option: ";
  getline(cin, id);
  cout<<endl;

  while(flag) {
    for(int i=0; i<id.length(); i++){ // Checking if the given input is only numbers.
      if(isdigit(id[i]) == 0) {
        cout<<"\x1B[2J\x1B[H";
        cout<<"Invalid ID! Please enter a valid one (1000 - 2000): "; // Display error message if input is not valid.
        getline(cin, id);
        flag = true;
        break;
      }
      else {
        flag = false;
      }
    }
    if (flag == false) {
      if (stoi(id) < 1000 || stoi(id) > 2000) { // Check if the input is in the range 1000 - 2000.
        cout<<"\x1B[2J\x1B[H";
        cout<<"Invalid ID! Please enter a valid one (1000 - 2000): "; // Display error message if input is not valid.
        getline(cin, id);
        flag = true;
      }
      else {
        break; // Exit while loop if input is only numbers and in the valid range.
      }
    }
  }
  return stoi(id); // return the converted string ID input converted to int.
}

int searchByPrice(string animal, string minORmax) { // To ask for a price range to search for.
  string input_price;
  bool flag = true;
  cout<<"\x1B[2J\x1B[H";
  cout<<"What is the "<<animal<<"'s "<<minORmax<<" price? (1 - 100)"<<endl;
  cout<<"Option: £";
  getline(cin, input_price);
  cout<<endl;

  while(flag) {
    for(int i=0; i<input_price.length(); i++){ // Checking if the given input is only numbers.
      if(isdigit(input_price[i]) == 0) {
        cout<<"Invalid price! Please enter a valid "<<minORmax<<" price (1 - 100): "; // Display error message if input is not valid.
        getline(cin, input_price);
        flag = true;
        break;
      }
      else {
        flag = false;
      }
    }
    if (flag == false) {
      if (stoi(input_price) < 1 || stoi(input_price) > 100) { // Check if the input is in the range 1 - 100.
        cout<<"Invalid price! Please enter a valid "<<minORmax<<" price (1 - 100): "; // Display error message if input is not valid.
        getline(cin, input_price);
        flag = true;
      }
      else {
        break; // Exit while loop if input is only numbers and in the valid range.
      }
    }
  }

  return stoi(input_price);
}

// Printing animals based on given type and ID and/or price range.
void printAnimal(string animal, int id, int minPrice, int maxPrice, vector<Cat*> cat, vector<Dog*> dog, vector<Bird*> bird) {
  int count = 0;
  switch (animal[0]) {
    case 'C': // For when the type to search is a cat.
      if (id != 0) { // Checking if an ID to search was given.
        if (minPrice != 0 && maxPrice != 0) { // Checking if a price range to search was given.
          for (int i=0; i<cat.size(); i++) { // Find cats with given ID and price range.
            if (cat[i]->getID() == id && (cat[i]->getPrice() >= minPrice && cat[i]->getPrice() <= maxPrice)) {
              printCats(cat, i); // Print cats with found parameters.
              count += 1;
            }
          }
          cout<<"The following number of results were produced: "<<count<<"\n\n";
        }
        else { // Print cats based only on their ID.
          for (int i=0; i<cat.size(); i++) {
            if (cat[i]->getID() == id) {
              printCats(cat, i);
              count += 1;
            }
          }
          cout<<"The following number of results were produced: "<<count<<"\n\n";
        }
      }
      else if (minPrice != 0 && maxPrice != 0) { // Print cats based only on their price range.
          for (int i=0; i<cat.size(); i++) {
            if (cat[i]->getPrice() >= minPrice && cat[i]->getPrice() <= maxPrice) {
              printCats(cat, i);
              count += 1;
            }
          }
          cout<<"The following number of results were produced: "<<count<<"\n\n";
        }
      else { //print cat only by type.
        for (int i=0; i<cat.size(); i++) {
          printCats(cat, i);
          count += 1;
        }
        cout<<"The following number of results were produced: "<<count<<"\n\n";
      }
    break;

    case 'D': // For when the type to search is a dog.
      if (id != 0) { // Checking if an ID to search was given.
        if (minPrice != 0 && maxPrice != 0) { // Checking if a price range to search was given.
          for (int i=0; i<dog.size(); i++) { // Find dogs with given ID and price range.
            if (dog[i]->getID() == id && (dog[i]->getPrice() >= minPrice && dog[i]->getPrice() <= maxPrice)) {
              printDogs(dog, i); // Print dogs with found parameters.
              count += 1;
            }
          }
          cout<<"The following number of results were produced: "<<count<<"\n\n";
        }
        else { // Print dogs based only on their ID.
          for (int i=0; i<dog.size(); i++) {
            if (dog[i]->getID() == id) {
              printDogs(dog, i);
              count += 1;
            }
          }
          cout<<"The following number of results were produced: "<<count<<"\n\n";
        }
      }
      else if (minPrice != 0 && maxPrice != 0) { // Print dogs based only on their price range.
          for (int i=0; i<dog.size(); i++) {
            if (dog[i]->getPrice() >= minPrice && dog[i]->getPrice() <= maxPrice) {
              printDogs(dog, i);
              count += 1;
            }
          }
          cout<<"The following number of results were produced: "<<count<<"\n\n";
        }
      else { //print dog only by type.
        for (int i=0; i<dog.size(); i++) {
          printDogs(dog, i);
          count += 1;
        }
        cout<<"The following number of results were produced: "<<count<<"\n\n";
      }
    break;

    default: // For when the type to search is a bird.
      if (id != 0) { // Checking if an ID to search was given.
        if (minPrice != 0 && maxPrice != 0) { // Checking if a price range to search was given.
          for (int i=0; i<bird.size(); i++) { // Find birds with given ID and price range.
            if (bird[i]->getID() == id && (bird[i]->getPrice() >= minPrice && bird[i]->getPrice() <= maxPrice)) {
              printBirds(bird, i); // Print birds with found parameters.
              count += 1;
            }
          }
          cout<<"The following number of results were produced: "<<count<<"\n\n";
        }
        else { // Print birds based only on their ID.
          for (int i=0; i<bird.size(); i++) {
            if (bird[i]->getID() == id) {
              printBirds(bird, i);
              count += 1;
            }
          }
          cout<<"The following number of results were produced: "<<count<<"\n\n";
        }
      }
      else if (minPrice != 0 && maxPrice != 0) { // Print birds based only on their price range.
          for (int i=0; i<bird.size(); i++) {
            if (bird[i]->getPrice() >= minPrice && bird[i]->getPrice() <= maxPrice) {
              printBirds(bird, i);
              count += 1;
            }
          }
          cout<<"The following number of results were produced: "<<count<<"\n\n";
        }
      else { //print dog only by type.
        for (int i=0; i<bird.size(); i++) {
          printBirds(bird, i);
          count += 1;
        }
        cout<<"The following number of results were produced: "<<count<<"\n\n";
      }
    break;
  }
}

// Used to print only neutered and/or vaccinated and/or council licenced animals.
void printByDetails(vector<Cat*> cat, vector<Dog*> dog, vector<Bird*> bird, string choice1, string choice2, string choice3) {
  int count = 0;
  cout<<endl;
  if (choice1 == "yes" && choice2 == "yes") { // Print animals that have been neutered and vaccinated.
    // Vaccine and council.
    for (int i=0; i<cat.size(); i++) {
      if (cat[i]->cat_neutered == "YES" && cat[i]->cat_vaccinated == "YES") {
        printCats(cat, i);
        count += 1;
      }
    }
    for (int i=0; i<dog.size(); i++) {
      if (dog[i]->dog_neutered == "YES" && dog[i]->dog_vaccinated == "YES" ) {
        printDogs(dog, i);
        count += 1;
      }
    }
    if (choice3 == "yes") { // Print birds which are council licenced.
      for (int i = 0; i<bird.size(); i++) {
        if (bird[i]->council_licenced == "YES") {
        printBirds(bird, i);
        count += 1;
        }
      }
    }
    cout<<"A total of "<<count<<" results were found.\n";
  }

  else if (choice1 == "no" && choice2 == "yes") { // Print animals that have only been vaccinated.
    //"Vaccine only"
    for (int i=0; i<cat.size(); i++) {
      if (cat[i]->cat_neutered == "NO" && cat[i]->cat_vaccinated == "YES") {
        printCats(cat, i);
        count += 1;
      }
    }
    for (int i=0; i<dog.size(); i++) {
      if (dog[i]->dog_neutered == "NO" && dog[i]->dog_vaccinated == "YES" ) {
        printDogs(dog, i);
        count += 1;
      }
    }
    if (choice3 == "yes") { // Print birds which are council licenced.
      for (int i = 0; i<bird.size(); i++) {
        if (bird[i]->council_licenced == "YES") {
        printBirds(bird, i);
        count += 1;
        }
      }
    }
    cout<<"A total of "<<count<<" results were found.\n";
  }

  else if (choice1 == "yes" && choice2 == "no") { // Print animals that have only been neutered.
    //"Vaccine only"
    for (int i=0; i<cat.size(); i++) {
      if (cat[i]->cat_neutered == "YES" && cat[i]->cat_vaccinated == "NO") {
        printCats(cat, i);
        count += 1;
      }
      if (dog[i]->dog_neutered == "YES"&& dog[i]->dog_vaccinated == "NO") {
        printDogs(dog, i);
        count += 1;
      }
    }
    if (choice3 == "yes") { // Print birds which are council licenced.
      for (int i = 0; i<bird.size(); i++) {
        if (bird[i]->council_licenced == "YES") {
        printBirds(bird, i);
        count += 1;
        }
      }
    }
    cout<<"A total of "<<count<<" results were found.\n";
  }
  else if (choice1 == "no" && choice2 == "no" && choice3 == "yes") { // Print only council licenced birds.
    // Council only
    for (int i=0; i<bird.size(); i++) {
      if (bird[i]->council_licenced == "YES") {
        printBirds(bird, i);
        count += 1;
      }
    }
    cout<<"A total of "<<count<<" results were found.\n";
  }

  else { // Message saying no animals will be printed since no attributes where specified.
    cout<<"No details have been chosen to filter by.\n";
  }
}

// Printing all animals stored in the vector.
void printAllAnimals(vector<Cat*> cat, vector<Dog*> dog, vector<Bird*> bird) {

  int total = cat.size() + dog.size() + bird.size();
  for (int i=0; i<cat.size(); i++) { // Printing all cats.
      printCats(cat, i);
  }
  for (int i=0; i<dog.size(); i++) { // Printing all dogs.
      printDogs(dog, i);
  }
  for (int i=0; i<bird.size(); i++) { // Printing all birds.
      printBirds(bird, i);
  }
  // Message printing the total number of animals printed.
  cout<<"A total of "<<total<<" animals are saved in the inventory."<<endl;
}

// Checks if the inputted ID for the animal to remove is a valid one.
int checkID(string msg) {
  bool flag = true;
  string id;

  cout<<msg; // Print message to display.
  getline(cin, id);
  cout<<endl;

  while(flag) {
    for(int i=0; i<id.length(); i++){ // Checking if the given input is only numbers.
      if(isdigit(id[i]) == 0) {
        cout<<"Invalid ID! "<<msg; // Display error message if input is not valid.
        getline(cin, id);
        flag = true;
        break;
      }
      else {
        flag = false;
      }
    }
    if (flag == false) {
      if (stoi(id) < 1000 || stoi(id) > 2000) { // Check if the input is 1 or 2.
        cout<<"Invalid ID! "<<msg; // Display error message if input is not valid.
        getline(cin, id);
        flag = true;
      }
      else {
        flag = true;
        break; // Exit while loop if input is only numbers and in the valid range.
      }
    }
  }
  return stoi(id); // Returning the ID of the animal to remove.
}

// Used to remove a Cat, Dog or Bird object based on a given ID.
void removeAnimal(vector<Cat*> &cat, vector<Dog*> &dog, vector<Bird*> &bird) {
  int flag = 0;
  int id;
  string animal, msg;

  cout<<"\nWhat animal do you want to REMOVE?"<<endl; // Asking the type of animal to remove.
  cout<<"- Cat\n- Dog\n- Bird\n\n";
  cout<<"Option: ";
  cin>>animal;
  cout<<endl;

  //Stay in the while loop until a correct input has been given.
  while (animal != "Cat" && animal != "Dog" && animal != "Bird") {
    cout<<"\nSorry there's no such animal! What type of animal Do you want REMOVE?"<<endl;
    cout<<"- Cat\n- Dog\n- Bird\n\n";
    cout<<"Option: ";
    cin>>animal;
    cout<<endl;
  }

  cin.clear();
  cin.ignore(50, '\n');

  switch (animal[0]) {
    case 'C': // Option if a cat is to be deleted.
      msg = "Specify the ID of the Cat to REMOVE (1000 - 2000): ";
      id = checkID(msg); // To input the ID of the cat to remove.

      // Searching for the cat to remove.
      for (int i=0; i<cat.size(); i++) {
        if(cat[i]->getID() == id) {
          // Successful retrieval and removal.
          cat.erase(cat.begin() + i);
          cout<<"The cat with the ID "<<id<< " was successfully removed."<<endl;
          flag = 0;
          break;
        }
        else{ flag = 1; }
      }
      if (flag == 1) {
        // Unsuccessful retrieval.
        cout<<"No cat with the ID "<<id<<" was found. Sorry."<<endl;
      }
    break;

    case 'D': // Option if a dog is to be deleted.
      msg = "Specify the ID of the Dog to REMOVE (1000 - 2000): ";
      id = checkID(msg); // To input the ID of the dog to remove.

      // Searching for the dog to remove.
      for (int i=0; i<dog.size(); i++) {
        if(dog[i]->getID() == id) {
          // Successful retrieval and removal.
          dog.erase(dog.begin() + i);
          cout<<"The dog with the ID "<<id<< " was successfully removed."<<endl;
          flag = 0;
          break;
        }
        else { flag = 1; }
      }
      if (flag == 1) {
        // Unsuccessful retrieval.
        cout<<"No dog with the ID "<<id<<" was found. Sorry."<<endl;
      }
      break;

    default: // Option if a bird is to be deleted.
    msg = "Specify the ID of the Bird to REMOVE (1000 - 2000): ";
    id = checkID(msg); // To input the ID of the bird to remove.

      // Searching for the bird to remove.
      for (int i=0; i<bird.size(); i++) {
        if(bird[i]->getID() == id) {
          // Successful retrieval and removal.
          bird.erase(bird.begin() + i);
          cout<<"The bird with the ID "<<id<< " was successfully removed."<<endl;
          flag = 0;
          break;
        }
        else { flag = 1; }
      }
      if (flag == 1) {
        // Unsuccessful retrieval.
        cout<<"No bird with the ID "<<id<<" was found. Sorry."<<endl;
      }
      break;
  }
}

void addAnimal(vector<Cat*> &cat, vector<Dog*> &dog, vector<Bird*> &bird) {
  string animal;
  cout<<"\nWhat animal do you want to ADD?"<<endl; // Asking the animal to add.
  cout<<"- Cat\n- Dog\n- Bird\n\n";
  cout<<"Option: ";
  cin>>animal;
  cout<<endl;

  //Stay in the while loop until a correct input has been given.
  while (animal != "Cat" && animal != "Dog" && animal != "Bird") {
    cout<<"\x1B[2J\x1B[H";
    cout<<"\nSorry there's no such animal! What type of animal Do you want to ADD?"<<endl;
    cout<<"- Cat\n- Dog\n- Bird\n\n";
    cout<<"Option: ";
    cin>>animal;
    cout<<endl;
  }

  switch (animal[0]) {
    case 'C': // Option to add a cat.
      addCat(cat, animal); // Call function to add a cat.
    break;

    case 'D': // Option to add a dog.
      addDog(dog, animal); // Call function to add a dog.
    break;

    default: // Option to add a bird.
      addBird(bird, animal); // Call function to add a bird.
    break;
  }
}

// Function saving updated list of all pets (added and/or removed) to a file.
void saveExit(vector<Cat*> cat, vector<Dog*> dog, vector<Bird*> bird) {
  // Open (or create a file if non-existent) to save contents to it.
  ofstream outputFile("petsInventory.txt");

  // Saving all the cats to the file.
  for (int i = 0; i<cat.size(); i++) {
    outputFile<<cat[i]->getType()<<"\n";
    outputFile<<cat[i]->getID()<<"\n";
    outputFile<<cat[i]->getBreed()<<"\n";
    outputFile<<cat[i]->getAge()<<"\n";
    outputFile<<cat[i]->getColour()<<"\n";
    outputFile<<cat[i]->getOrigin()<<"\n";
    outputFile<<cat[i]->getPrice()<<"\n";
    outputFile<<cat[i]->cat_neutered<<"\n";
    outputFile<<cat[i]->cat_vaccinated<<"\n";
    outputFile<<"\n";
  }

  // Saving all the dogs to the file.
  for (int i = 0; i<dog.size(); i++) {
    outputFile<<dog[i]->getType()<<"\n";
    outputFile<<dog[i]->getID()<<"\n";
    outputFile<<dog[i]->getBreed()<<"\n";
    outputFile<<dog[i]->getAge()<<"\n";
    outputFile<<dog[i]->getColour()<<"\n";
    outputFile<<dog[i]->getOrigin()<<"\n";
    outputFile<<dog[i]->getPrice()<<"\n";
    outputFile<<dog[i]->dog_neutered<<"\n";
    outputFile<<dog[i]->dog_vaccinated<<"\n";
    outputFile<<"\n";
  }

  // Saving all the birds to the file.
  for (int i = 0; i<bird.size(); i++) {
    outputFile<<bird[i]->getType()<<"\n";
    outputFile<<bird[i]->getID()<<"\n";
    outputFile<<bird[i]->getBreed()<<"\n";
    outputFile<<bird[i]->getAge()<<"\n";
    outputFile<<bird[i]->getColour()<<"\n";
    outputFile<<bird[i]->getOrigin()<<"\n";
    outputFile<<bird[i]->getPrice()<<"\n";
    outputFile<<bird[i]->council_licenced<<"\n";
    outputFile<<"\n";
  }
  outputFile.close(); // Closing the recently opened file.
}

// To check if a valid yes or no input has been given.
void checkQuestion(string msg, string &input) {
  cout<<msg; // Print message to answer.
  cin>>input;
  // Check if the input is valid.
  while (input != "yes" && input != "no") {
    cout<<"\nInvalid option! "<<msg;
    cin>>input;
  }
}

int main() {
  // Vectors used to store details of cats, dogs and birds.
  vector<Cat*> cat;
  vector<Dog*> dog;
  vector<Bird*> bird;

  // Read a file's contents and create initial set of values.
  // Returns bool value saying if the file can or cannot be opened.
  bool openORnot = createAnimal(cat, dog, bird);

  if (openORnot == false) {
    // If file cannot be opened show error message and terminate the program.
    // Otherwise continue with the normal program flow.
    cout<<"\x1B[2J\x1B[H";
    cout<<"Cannot find the file containing the inventory."<<endl;
    cout<<"Please fix the error before using the Family Pet Shop Inventory. Goodbye!\n\n";
    return 0;
  }

  // Displaying the main menu.
  cout<<"\x1B[2J\x1B[H";
  cout<<endl<<"\t\tFamily Pet Shop (Inventory)\n\n";
  string selection;
  mainMenu(selection);

  string option, msg, choice1, choice2, choice3, animal;
  string quit = "yes";
  int id = 0;
  int minPrice = 0;
  int maxPrice = 0;

  // Enter secondary menu if so selected from the main menu.
  if (selection == "1") {
    // Stay in the secondary menu until "no" is entered in the command line.
    while (quit == "yes") {
      cout<<"\x1B[2J\x1B[H";
      secondaryMenu(option); // Display the secondary menu.

      //Do actions based on the selection from the secondary menu.
      switch (option[0]) {
        case '1': // Option to search and display pets by type and ID and/or price range.
          searchByType(animal); // Asking what type of animal to search for.
          // Asking whether to search animals also by their ID.
          msg = "Search the "+ animal +" by its ID too? (yes/no)\n";
          checkQuestion(msg, choice1);
          if (choice1 == "yes") {
            id = searchByID(animal); // Asking the user for the ID to search for.
          }

          // Asking whether to search animals also by their price range.
          msg = "Search the "+ animal +" by its price range too? (yes/no)\n";
          checkQuestion(msg, choice1);
          if (choice1 == "yes") {
            cin.clear();
            cin.ignore(50, '\n');
            minPrice = searchByPrice(animal, "min"); // Asking the user for the price range to search for.
            maxPrice = searchByPrice(animal, "max");
          }
          //Printing the animal(s) with the given parameters based on the previous questions.
          cout<<"\x1B[2J\x1B[H";
          printAnimal(animal, id, minPrice, maxPrice, cat, dog, bird);
          break;

        case '2': // Option to search and display pets by neutered and council licence status.
          cout<<"\x1B[2J\x1B[H";
          msg = "Do you wish to display neutered pets? (yes/no): ";
          checkQuestion(msg, choice1);

          cout<<"\x1B[2J\x1B[H";
          msg = "Do you wish to display vaccinated pets? (yes/no): ";
          checkQuestion(msg, choice2);

          cout<<"\x1B[2J\x1B[H";
          msg = "Do you wish to display council licenced pets? (yes/no): ";
          checkQuestion(msg, choice3);

          // Printing the animals based on previous options chosen by the user.
          printByDetails(cat, dog, bird, choice1, choice2, choice3);
        break;

        case '3': // Option to display all pets, add new ones or remove one.
          cout<<"\x1B[2J\x1B[H";
          printAllAnimals(cat, dog, bird); // To print all pets.

          msg = "\nDo you wish to REMOVE an animal from the inventory? (yes/no)\n";
          checkQuestion(msg, choice1);
          if (choice1 == "yes") {
            removeAnimal(cat, dog, bird); // To remove a pet using their ID.
          }

          msg = "\nDo you wish to ADD an animal to the inventory? (yes/no)\n";
          checkQuestion(msg, choice1);
          if (choice1 == "yes") {
            cout<<"\x1B[2J\x1B[H";
            addAnimal(cat, dog, bird); // To add a pet.
          }

          break;

        default: // Option to terminate the Pet Shop Inventory.
          cout<<"\x1B[2J\x1B[H";
          cout<<"Thank you for using the Family Pet Shop Inventory. Goodbye!\n\n";
          return 0;
      }
      // Asking the user whether to continue on using the Pet Shop Inventory.
      msg = "\nDo you wish to continue on using the Family Pet Shop Inventory? (yes/no)\n";
      checkQuestion(msg, quit);
      cin.clear();
      cin.ignore(50, '\n');
    }
  }

  saveExit(cat, dog, bird); // Saving all Pets (along added and removed ones) to a file.

  // Exit message displayed before the program finishes.
  cout<<"\x1B[2J\x1B[H";
  cout<<"Thank you for using the Family Pet Shop Inventory. Goodbye!\n\n";

  // Freeing up memory allocated to the vectors cat, dog and bird.
  // Their capacities have also been reduced to zero using the shrink_to_fit() function.
  // This helps up reduce as much memory as possible.
  cat.clear();
  cat.shrink_to_fit();
  dog.clear();
  dog.shrink_to_fit();
  bird.clear();
  bird.shrink_to_fit();
  return 0;
}
