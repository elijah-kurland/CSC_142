/*Elijah Kurland
April 16, 2025
This code creates a pair of strings that represent a name and location. 
It then prints them both by using .first and .second.*/

#include <iostream> //used for input and output
#include <utility> //used for pair
using namespace std;

int main(){
    //creates a pair of strings to represent name and location
    pair<string, string> alert{"Joker", "Arkham Asylum",};

    //prints message with the pair elements
    cout << alert.first << " spotted at " << alert.second <<"!\n";

    return 0;
}