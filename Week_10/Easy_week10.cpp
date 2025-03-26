/*Elijah Kurland
March 24, 2025
This code uses pointers and references to create a player hp and change it based on two scenarios.*/

#include <iostream>
using namespace std;

//function that increases hero's HP by healing amount
//uses a reference to modify the original HP variable
void drinkPotion(int& hp, int healing) {
    hp += healing;
}

//function that decreases hero's HP by damage amount
//uses a pointer to modify the original HP variable
void damageHero(int* hp, int damage) {
    *hp -= damage;
}

int main() {
    int heroHP = 20; //initializes hero HP

    cout << "Hero's starting HP: " << heroHP << endl;

    //increases HP by 10
    cout << "Hero drinks a healing potion (+10 HP)." << endl;
    drinkPotion(heroHP, 10);
    cout << "Hero's current HP: " << heroHP << endl;

    //decreases HP by -5
    cout << "Hero takes damage from a goblin (-5 HP)." << endl;
    damageHero(&heroHP, 5);

    //returns current HP
    cout << "Hero's current HP: " << heroHP << endl;

    return 0;
}