/*Speed_Trap.cpp
Elijah Kurland
Jan. 29, 2025
This program will use conditional statements to check if the driver is speeding or not*/

#include <iostream>
using namespace std;

int main(){
    int speed_limit; //stores speed limit
    double driver_speed; //stores driver speed

    cout << "Please enter the current speed limit: "; //prompts user to input speed limit
    cin >> speed_limit;

    cout << "Please enter your current speed: "; //prompts user to input their speed
    cin >> driver_speed;

    //checks to see if the driver is speeding and prints the according message
    if (driver_speed <= speed_limit) {
        cout << "Your speed is legal.\n";
    }else{
        cout << "You will recieve a speeding ticket.";
    }
    return 0;
}