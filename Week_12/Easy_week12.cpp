/*Elijah Kurland
April 2, 2025
This code creates a D&D style scenario for a potion shopkeeper. 
It uses if else statements and basic arithmetic operations to complete 
this by giving the user 100 coins to spend on items and subtracting the ones spent.*/

#include <iostream> //used for input and output
using namespace std;

int main() {
    int gold = 100; //player's starting gold
    int potion_cost = 10; //each potion cost
    int potions; //variable to store number of potions player buys

    //display welcome message and potion cost
    cout << "Welcome to the Potion Shop!\n";
    cout << "Each healing potion costs " << potion_cost << " gold pieces.\n\n";

    //prompts player to enter number of potions they want
    cout << "How many potions would you like to buy? ";
    cin >> potions; //stores user input

    //calculates total cost of desired potions
    int total_cost = potions * potion_cost;

    //checks if player has enough gold to make purchase
    if (total_cost <= gold) {
        gold -= total_cost; //subtracts total cost from player's gold
        cout << "You bought " << potions << " potions for " << total_cost << " gold pieces.\n";
        cout << "You now have " << gold << " gold pieces left. Safe travels, adventurer!\n";
    } else {
        //if the player doesn't have enough gold, print "you only have___gold pieces"
        cout << "You do not have enough gold to buy " << potions << " potions.\n";
        cout << "You only have " << gold << " gold pieces.\n";
    }

    return 0;
}