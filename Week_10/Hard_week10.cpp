/*Elijah Kurland
March 24, 2025
This code implements a class called MagicItem that stores items. Each item has different power types and charges. 
Each item is called until the charge amount is zero.*/

#include <iostream>
#include <string>
using namespace std;

//class representing a magical item with a name, power type, and limited charges
class MagicItem {
public:
    //constructor initializes the item's name, power type, and number of charges
    MagicItem(const string& name, const string& powerType, int charges)
        : name_{name}, powerType_{powerType}, charges_{charges} {
        cout << name_ << " (" << powerType_ << " power) created with " << charges_ << " charges!\n";
    }

    //function to use item
    void use() {
        if (charges_ > 0) {
            charges_--; //reduces number of charges
            cout << name_ << " (" << powerType_ << " power) used! Charges left: " << charges_ << "\n";
        } else {
            cout << name_ << " (" << powerType_ << " power) has no charges left!\n";
        }
    }

private:
    string name_; //name of item
    string powerType_; //power type of item
    int charges_; //number of times an item can be used
};

int main() {
    //creating magic item: Binary Blade with 3 charges
    MagicItem blade{"Binary Blade", "Binary", 3};
    blade.use();
    blade.use();
    blade.use();
    blade.use();

    //creating magic item: String Sword with 2 charges
    MagicItem sword{"String Sword", "Strings", 2};
    sword.use();
    sword.use();
    sword.use();

    //creating magic item: Debugging Dagger with 1 charge
    MagicItem dagger{"Debugging Dagger", "Bugs", 1};
    dagger.use();
    dagger.use();

    return 0;
}