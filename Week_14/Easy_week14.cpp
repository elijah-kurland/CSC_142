/*Elijah Kurland
April 14, 2025
This code uses a function coutdown_to_lightspeed that gets called from 
a main function to print a statement when it gets to 0.*/

#include <iostream> //used for input and output
using namespace std;

//function for calculations
void countdown_to_lightspeed(int seconds){
    for (int i = seconds; i > 0; --i) {
        cout << "Jumping to hyperspace in " << i << "...\n";
    }
    cout << "Punch it Chewie!\n"; //prints after 1
}

//main that stores the number to count down from
int main(){
    countdown_to_lightspeed(5);
    return 0;
}