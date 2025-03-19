/*Elijah Kurland
March 17, 2025
This code will print out a list of characters with different classes, names, types, health, and strengths.*/

#include <iostream> //for using input and output
#include <string> //for using strings

//defines enumeration class
enum class CharacterClass { Warrior, Mage, Archer, Rogue };

//user-defined class
struct Character {
    std::string name;
    CharacterClass type;
    int health;
    float strength;
};

//function that converts enum to string
std::string classToString(CharacterClass type) {
    switch(type) {
        case CharacterClass::Warrior: return "Warrior";
        case CharacterClass::Mage:    return "Mage";
        case CharacterClass::Archer:  return "Archer";
        case CharacterClass::Rogue:   return "Rogue";
        default:                      return "Unknown";
    }
}

int main() {
    //array of characters to be initialized
    Character characters[4]{

        {"Aragon",  CharacterClass::Warrior, 100, 90.5f},
        {"Gandalf", CharacterClass::Mage,    120, 75.0f},
        {"Legolas", CharacterClass::Archer,   85, 80.0f},
        {"Frodo",   CharacterClass::Rogue,    80, 60.5f}
    };

    //prints character details
    std::cout << "Characters:\n------------\n";
    for (int i = 0; i < 4; i++) {
        std::cout << "Name: " << characters[i].name 
                  << ", Type: " << classToString(characters[i].type)
                  << ", Health: " << characters[i].health
                  << ", Strength: " << characters[i].strength
                  << std::endl;
    }

    //calculates average health
    int sumHealth = 0;
    for (int i = 0; i < 4; i++) {
        sumHealth += characters[i].health;
    }
    //converts one data type into another
    float avgHealth = static_cast<float>(sumHealth) / 4.0f;
    
    std::cout << "\nAverage Health: " << avgHealth << std::endl;

    return 0;
}