/*Elijah Kurland
March 31, 2025
This code creates a class Goblin and uses construction and destruction to summon and destroy.*/

#include <iostream>
using namespace std;

class Goblin { //creates class Goblin
public:
    //constructor
    Goblin() {
        cout << "A Goblin has been summoned!" << endl;
    }

    //destructor
    ~Goblin() {
        cout << "The Goblin has been vanquished!" << endl;
    }
};

int main() {
    {
        Goblin goblin; //goblin is created here
    } //destructor gets called

    return 0;
}