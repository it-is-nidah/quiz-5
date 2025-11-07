/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>  // for rand()
#include <ctime>    // for time()

using namespace std;

// Structure definition
struct Animal {
	string name;
	int age;
	int hunger;  // 0 = starving, 100 = full
};

// Function declarations
void displayMenu();
void displayAnimals(const vector<Animal>& animals);
void feedAnimal(vector<Animal>& animals, const string& nameToFeed);
void addAnimal(vector<Animal>& animals);
void removeAnimal(vector<Animal>& animals);
void simulateDay(vector<Animal>& animals);
void pointerDemo(Animal* aPtr);


int main() {
	// Phase 1: Variables and Input
	string zookeeperName, zooName;
	int age;
	cout << "Enter your name: ";
	cin >> zookeeperName;
	cout << "Enter your age: ";
	cin >> age;
	cout << "Enter the name of your zoo: ";
	cin >> zooName;


	cout << "\nHello " << zookeeperName << "! Welcome to " << zooName << " " << endl;
	cout << "-------------------------------------------" << endl;

	// Phase 2: Initial Animal Data
	// TODO: Initialize a few animals in a vector (3CB"C"b B,C"b,E4 animals with sample data)
	vector<Animal> animals;
	animals.push_back({"Lion", 4, 100});
	animals.push_back({"Bear", 3, 100});
	animals.push_back({"Tiger", 2, 100});


	// Seed random generator for simulation
	srand(time(0));

	int choice;
	do {
		displayMenu();
		cout << "Choose an option: ";
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1:
			displayAnimals(animals);
			break;
		case 2: {
			string name;
			cout << "Enter the name of the animal to feed: ";
			getline(cin, name);
			feedAnimal(animals, name);
			break;
		}
		case 3:
			addAnimal(animals);
			break;
		case 4:
			removeAnimal(animals);
			break;
		case 5:
			simulateDay(animals);
			break;
		case 6:
			cout << "Pointer demo: Feeding first animal directly using pointer...\n";
			if (!animals.empty()) {
				pointerDemo(&animals[0]);
			}
			break;
		case 7:
			cout << "Exiting " << zooName << " Zoooo... Goodbye, " << zookeeperName << endl;
			break;
		default:
			cout << "Invalid choice. Try again.\n";
		}

	} while (choice != 7);

	return 0;
}

// Function definitions

// TODO: Define displayMenu()
// HINT: Show a numbered list of options for the user.
void displayMenu() {
	cout << "Main Menu" << endl;
	cout << "1. View animals" << endl;
	cout << "2. Feed animals" << endl;
	cout << "3. Add a new animal" << endl;
	cout << "4. Remove animal" << endl;
	cout << "5. End day" << endl;
	cout << "6. Pointer demo" << endl;
	cout << "7. Exit" << endl;
}

// TODO: Define displayAnimals()
// HINT: Loop through all animals and print their name, age, and hunger.
// If hunger < 50, show a warning message.
void displayAnimals(const vector<Animal>& animals) {
	for (int i = 0; i < animals.size(); ++i) {
		cout << animals[i].name << ": Age " << animals[i].age << ": Hunger " << animals[i].hunger << endl;
		if (animals[i].hunger < 50) {
			cout << animals[i].name << " is getting hungry!!" << endl;
		}
	}
}

// TODO: Define feedAnimal()
// HINT: Use a loop to find the animal by name and increase hunger by 10 (max 100).
void feedAnimal(vector<Animal>& animals, const string& nameToFeed) {
	bool found = false;

	for (int i = 0; i < animals.size(); ++i) {
		if (animals[i].name == nameToFeed) {
			animals[i].hunger += 10;
			if (animals[i].hunger > 100)
				animals[i].hunger = 100;

			cout << animals[i].name << " has been fed. Hunger is now "
			     << animals[i].hunger << ".\n";
			found = true;
			break;
		}
	}
}

// TODO: Define addAnimal()
// HINT: Ask user for name and age, set hunger = 100, then push_back to vector.
void addAnimal(vector<Animal>& animals) {
	Animal a;
	cout << "Enter animal name: " << endl;
	cin.ignore();
	cin >> a.name;
	cout << "Enter age: " << endl;
	cin >> a.age;
	a.hunger = 100;
	animals.push_back(a);
	cout << a.name << " has been added." << endl;
}

// TODO: Define removeAnimal()
// HINT: Loop through vector and erase the matching animal by name.
void removeAnimal(vector<Animal>& animals) {
	displayAnimals(animals);
	cout << "Enter the animals you want to remove." << endl;
	int choice;
	cin >> choice;
	cout << animals[choice - 1].name << " has been removed." << endl;
	animals.erase(animals.begin() + (choice - 1));
}

// TODO: Define simulateDay()
// HINT: For each animal, decrease hunger randomly between 0 and 20.
void simulateDay(vector<Animal>& animals) {
	for(int i = 0; i < animals.size(); ++i) {
		animals[i].hunger -= rand() % 21;
		if (animals[i].hunger < 0) animals[i].hunger = 0;
	}
	cout << "A new day has passed!!! Check your animals hunger levels" << endl;
}

// TODO: Define pointerDemo()
// HINT: Use a pointer to access and modify an animalCB"C"b B,C"b B"s hunger to 100.
void pointerDemo(Animal* aPtr) {
	aPtr->hunger = 100;
	cout << aPtr->name << " New hunger level: " << aPtr->hunger << endl;
}

