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
    getline(cin, zookeeperName);
    cout << "Enter your age: ";
    cin >> age;
    cin.ignore(); // clear newline left in buffer
    cout << "Enter the name of your zoo: ";
    getline(cin, zooName);

    cout << "\nHello " << zookeeperName << "! Welcome to " << zooName << " 🦁\n";
    cout << "-------------------------------------------\n";

    // Phase 2: Initial Animal Data
    vector<Animal> animals = {
        {"Lion", 4, 100},
        {"Bear", 3, 100},
        {"Tiger", 2, 100}
    };

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
                cout << "Exiting " << zooName << " Zoo... Goodbye, " << zookeeperName << "!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}

// ------------------ FUNCTION DEFINITIONS ------------------

void displayMenu() {
    cout << "\nMain Menu\n";
    cout << "1. View animals\n";
    cout << "2. Feed an animal\n";
    cout << "3. Add a new animal\n";
    cout << "4. Remove an animal\n";
    cout << "5. End day\n";
    cout << "6. Pointer demo\n";
    cout << "7. Exit\n";
}

void displayAnimals(const vector<Animal>& animals) {
    if (animals.empty()) {
        cout << "No animals in the zoo yet.\n";
        return;
    }

    cout << "\n--- Animal List ---\n";
    for (int i = 0; i < animals.size(); ++i) {
        cout << i + 1 << ". " << animals[i].name
             << " | Age: " << animals[i].age
             << " | Hunger: " << animals[i].hunger;
        if (animals[i].hunger < 50) {
            cout << " ⚠️ Getting hungry!";
        }
        cout << endl;
    }
}

void feedAnimal(vector<Animal>& animals, const string& nameToFeed) {
    bool found = false;
    for (auto& animal : animals) {
        if (animal.name == nameToFeed) {
            animal.hunger += 10;
            if (animal.hunger > 100) animal.hunger = 100;
            cout << animal.name << " has been fed. Hunger is now " << animal.hunger << ".\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No animal found with the name \"" << nameToFeed << "\".\n";
    }
}

void addAnimal(vector<Animal>& animals) {
    Animal a;
    cout << "Enter animal name: ";
    getline(cin, a.name);
    cout << "Enter animal age: ";
    cin >> a.age;
    cin.ignore();
    a.hunger = 100;
    animals.push_back(a);
    cout << a.name << " has been added to the zoo!\n";
}

void removeAnimal(vector<Animal>& animals) {
    if (animals.empty()) {
        cout << "No animals to remove!\n";
        return;
    }

    string nameToRemove;
    cout << "Enter the name of the animal to remove: ";
    getline(cin, nameToRemove);

    bool found = false;
    for (auto it = animals.begin(); it != animals.end(); ++it) {
        if (it->name == nameToRemove) {
            cout << it->name << " has been removed from the zoo.\n";
            animals.erase(it);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No animal found with the name \"" << nameToRemove << "\".\n";
    }
}

void simulateDay(vector<Animal>& animals) {
    if (animals.empty()) {
        cout << "No animals to simulate.\n";
        return;
    }

    for (auto& animal : animals) {
        animal.hunger -= rand() % 21;  // decrease by 0-20
        if (animal.hunger < 0) animal.hunger = 0;
    }
    cout << "A new day has passed! Check your animals' hunger levels.\n";
}

void pointerDemo(Animal* aPtr) {
    aPtr->hunger = 100;
    cout << aPtr->name << " has been fully fed using a pointer! Hunger: " << aPtr->hunger << "\n";
}
