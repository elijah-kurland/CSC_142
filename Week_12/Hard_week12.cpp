/*Elijah Kurland
April 2, 2025
This code mimics a turn based battle scenario by using a while loop to keep the 
combat going until a victory or defeat message is printed.
If else statements and rand is used for hit/missed conditions and dice rolls.*/

#include <iostream> //used for input and output
#include <cstdlib> //used for rand()
#include <ctime> //used for seeding random numbers
using namespace std;

//function to simulate a dice roll with a given number of sides
int rollDice(int sides) {
    return (rand() % sides) + 1; //generate a random number between 1 and 'sides'
}

int main() {
    srand(time(0)); //seed random number generator with current time for randomness

    //initialize Hero and Goblin attributes
    int hero_HP = 20, hero_AC = 15; //Hero's Hit Points (HP) and Armor Class (AC)
    int goblin_HP = 10, goblin_AC = 12; //Goblin's Hit Points (HP) and Armor Class (AC)

    cout << "Combat begins between Hero and Goblin!\n\n";

    //combat loop continues until one character's HP = 0
    while (hero_HP > 0 && goblin_HP > 0) {
        //Hero's turn
        cout << "-- Hero's turn --\n";
        int hero_roll = rollDice(20); //Hero rolls a d20 to determine attack hit
        cout << "Hero rolls a " << hero_roll;

        if (hero_roll >= goblin_AC) { //if hero's roll meets or exceeds goblin's AC, it's a hit
            int hero_damage = rollDice(8); //roll a d8 for damage
            goblin_HP -= hero_damage; //reduce goblin's HP
            cout << " and hits the Goblin!\n";
            cout << "Hero deals " << hero_damage << " damage. ";
            cout << "Goblin has " << (goblin_HP > 0 ? goblin_HP : 0) << " HP remaining.\n\n";
        } else {
            cout << " and misses!\n\n"; //hero's attack misses
        }

        if (goblin_HP <= 0) break; //exit loop if goblin is defeated

        //Goblin's turn
        cout << "-- Goblin's turn --\n";
        int goblin_roll = rollDice(20); //Goblin rolls a d20 to attack
        cout << "Goblin rolls a " << goblin_roll;

        if (goblin_roll >= hero_AC) { //if goblin's roll meets or exceeds hero's AC, it's a hit
            int goblin_damage = rollDice(6); //roll a d6 for damage
            hero_HP -= goblin_damage; //reduce hero's HP
            cout << " and hits!\n";
            cout << "Goblin deals " << goblin_damage << " damage. ";
            cout << "Hero has " << (hero_HP > 0 ? hero_HP : 0) << " HP remaining.\n\n";
        } else {
            cout << " and misses!\n\n"; //Goblin's attack misses
        }
    }

    //determine and display the winner
    if (hero_HP > 0) {
        cout << "Goblin is defeated! Hero wins the battle!\n";
    } else {
        cout << "Hero has fallen! Goblin wins the battle!\n";
    }

    return 0;
}