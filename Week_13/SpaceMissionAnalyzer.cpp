/*Elijah Kurland
April 7, 2025
This code works to analyze a space exploration mission and how viable the success rate is by using cmath to
run calculations on distance, fuel, weight, life support, and crew size.*/

#include <iostream> //used for input and output
#include <cmath> //used for cos and sin
#include <iomanip> //used for formatting
using namespace std;

int main(){
    //declares variables for input data
    double distance, fuel, spaceship_weight, life_support;
    int crew_size;

    //prompts user for planet distance
    cout << "Enter distance to planet (in million km): ";
    cin >> distance;

    //prompts user for available fuel
    cout << "Enter available fuel (in tons): ";
    cin >> fuel;

    //prompts user for crew size
    cout << "Enter the crew size: ";
    cin >> crew_size;

    //prompts user for spaceship weight
    cout << "Enter the spaceship weight (in tons): ";
    cin >> spaceship_weight;

    //prompts user for the duration of life support
    cout << "Enter the life support duration available (in days): ";
    cin >> life_support;

    //Calculations
    //fuel efficiency as a percentage of fuel to weight
    double efficiency = (fuel / spaceship_weight) * 100;

    //estimate speed based on fuel, crew size, and ship weight
    double speed = (fuel * 10000) / (crew_size * spaceship_weight);

    //convert distance from million km to km and calculate travel time in days
    double travel_time = (distance * 1000000) / speed;

    //round up travel time to nearest whole day
    int travel_days = static_cast<int>(ceil(travel_time));

    //checks if mission is viable through multiple conditions
    bool is_viable = (efficiency >= 20.0) &&
    (life_support >= travel_days + 10) &&
    (crew_size >= 2 && crew_size <=8) &&
    (spaceship_weight < 500);

    //set decimal precision to 2 for efficiency
    cout << fixed << setprecision(2);
    cout << "\nFuel efficiency: " << efficiency << "%\n";

    //set no decimal places for speed and time
    cout << setprecision(0);
    cout << "Estimated speed: " << speed << " km/day\n";
    cout << "Estimated travel time: " << travel_days << " days\n";

    //print mission status based on viability
    cout << "\nMission Status: ";
    if (is_viable) {
        cout << "Success!\n";
    } else {
        cout << "Mission Failed.\n";
    }
    return 0;
}