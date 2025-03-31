/*Elijah Kurland
March 31, 2025
This code creates a D&D style inventory system. It is managed by dynamic memory allocation, 
constructors, copy constructors, and destructors.*/

#include <iostream>
#include <string>
using namespace std;

class Inventory { //creates class Inventory
private:
    string* items; //stores items
    int capacity; //max number of items
    int count; //current number of items

public:
    //constructor
    Inventory(int cap = 10)
        : capacity(cap), count(0) {
        items = new string[capacity]; //allocate memory for items
    }

    //copy constructor
    Inventory(const Inventory& other)
        : capacity(other.capacity), count(other.count) {
        items = new string[capacity]; //allocate new mamory
        for (int i = 0; i < count; i++) {
            items[i] = other.items[i]; //copy items from original inventory
        }
    }

    //destructor
    ~Inventory() {
        delete[] items;
    }

    //adds an item
    void addItem(const string& item) {
        if (count < capacity) {
            items[count++] = item; //adds item and increment 
        } else {
            cout << "Inventory is full and no more items can be added!" << endl;
        }
    }

    //displays inventory contents
    void showInventory() const {
        for (int i = 0; i < count; i++) {
            cout << "- " << items[i] << endl;
        }
    }
};

int main() {
    //creates inventory and adds items
    Inventory inventory1;
    inventory1.addItem("Magic Sword");
    inventory1.addItem("Potion of Healing");

    //uses a copy constructor to create another inventory
    Inventory inventory2 = inventory1;
    inventory2.addItem("Bag of Holding");

    //displays inventories
    cout << "Inventory 1:" << endl;
    inventory1.showInventory();

    cout << "\nInventory 2:" << endl;
    inventory2.showInventory();

    return 0;
}