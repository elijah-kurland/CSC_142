/*Elijah Kurland
April 14, 2025
This code simulates a lightsaber duel through 5 rounds of either attack or defense. 
A print statement is then shown for who wins the most fights. This is done through ints.*/

#include <iostream> //used for input and output
#include <cstdlib> //used for rand() and srand()
#include <ctime> //used for time
using namespace std;

//simulates rolling an attack number between 1 and 10
int roll_attack() {
    return rand() % 10 + 1;
}

//simulates rolling an defense number between 1 and 10
int roll_defense() {
    return rand() % 10 + 1;
}

//determines if the attack hits based on higher attack than defense
bool is_hit(int attack, int defense) {
    return attack > defense;
}

//runs a 5-round duel between Obi-Wan and Darth Maul
void duel() {
    int obi_wins = 0;
    int maul_wins = 0;

    //loops through 5 rounds
    for (int i = 1; i <= 5; ++i) {
        int attack = roll_attack();
        int defense = roll_defense();

        //display attack and defense rolls
        cout << "Round " << i << ": Obi-Wan attacks with " << attack
                  << ", Maul defends with " << defense << " — ";

        //determines outcome
        if (is_hit(attack, defense)) {
            cout << "HIT!" << endl;
            ++obi_wins;
        } else {
            cout << "MISS!" << endl;
            ++maul_wins;
        }
    }

    //displays final results
    cout << "\nObi-Wan wins " << obi_wins << " rounds." << endl;
    cout << "Darth Maul wins " << maul_wins << " rounds." << endl;

    //declares winner
    if (obi_wins > maul_wins)
        cout << "Obi-Wan wins the duel!" << endl;
    else if (maul_wins > obi_wins)
        cout << "Darth Maul wins the duel!" << endl;
    else
        cout << "It's a tie!" << endl;
}

int main() {
    //seed the random number generator with current time
    srand(static_cast<unsigned int>(time(nullptr)));

    //starts the duel
    duel();
    return 0;
}