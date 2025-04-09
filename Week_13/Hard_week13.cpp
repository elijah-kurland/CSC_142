/*Elijah Kurland
April 7, 2025
This code computes the new coordinates of a spaceship before and after a hyperspace jump. 
The user inputs x,y,z and the code is modified using math cos and sin.*/

#include <iostream> //used for input and output
#include <cmath> //used for cos and sin
#include <iomanip> //used for formatting
using namespace std;

//sets constant for pi
constexpr double pi = 3.14159;

//funtion to convert degrees to radians
double degrees_to_radians(double degrees){
    return degrees * (pi/180.0);
}

int main(){
    double x, y, z;
    double thrust, angle_deg, warp_factor;

    //prompts user for coordinates
    cout << "Enter initial coordinates (x, y, z): ";
    cin >> x >> y >> z;
    
    //prompts user for thrust value
    cout << "Enter thrust: ";
    cin >> thrust;

    //prompts user for direction in degrees
    cout << "Enter angle degree: ";
    cin >> angle_deg;

    //prompts user for warp factor
    cout << "Enter warp factor: ";
    cin >> warp_factor;

    //converts angle from degrees to radians for trigonometric functions
    double angle_rad = degrees_to_radians(angle_deg);

    //calculates new coordinates
    double new_x = (x + thrust * cos(angle_rad)) * warp_factor;
    double new_y = (y + thrust * sin(angle_rad)) * warp_factor;
    double new_z = z + (thrust / warp_factor);

    //displays new coordinates
    cout << fixed << setprecision(3); //formatting
    cout << "\nNew coordinates after hyperspace jump: \n";
    cout << "X: " << new_x << "\n";
    cout << "Y: " << new_y << "\n";
    cout << "z: " << new_z << "\n";

    return 0;
}