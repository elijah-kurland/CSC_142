/*Elijah Kurland
April 7, 2025
This code uses a for loop to make a countdown from 10 to 1. 
When the last number is reached, the message Liftoff will be printed.*/

#include <iostream> //used for input and output
using namespace std;

int main () {
    cout << "Countdown: \n";
    //loop from 10 down to 1
    for (int i = 10; i >= 1; --i){
        //print current number
        cout << i << "...\n";
    }
    //print final message
    cout << "Liftoff!";
    
    return 0;
}