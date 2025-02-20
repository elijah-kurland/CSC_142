#include <iostream> //iniut and output
#include <iomanip> //formatting
#include "Rectangle.h" //defines the rectangle class
#include "RectangleDefinitions.cpp" //rectangle class definition

using namespace std;

int main() {
    //creates three rectangles (rooms)
    Rectangle kitchen, bedroom, livingRoom;
    //stores the user input for the length and width of rooms
    double len, wid;

    //demensions fof the kitchen
    cout << "What is the length of the kitchen? "; //prompt user for length
    cin >> len; //read input
    cout << "What is the width of the kitchen? "; //prompt user for width
    cin >> wid; //read input
    kitchen.setLength(len); //set length (using setLength method)
    kitchen.setWidth(wid); //set width (using setWidth method)

    //demensions for bedroom
    cout << "What is the length of the bedroom? "; //prompt user for length
    cin >> len; //read input
    cout << "What is the width of the bedroom? "; //prompt user for width
    cin >> wid; //read input
    bedroom.setLength(len); //set length (using setlength method)
    bedroom.setWidth(wid); //set width (using setWidth method)

    //demensions for living room
    cout << "What is the length of the living room? "; //prompt user for length
    cin >> len; //read input
    cout << "What is the width of the living room? "; //prompt user for width
    cin >> wid; //read input
    livingRoom.setLength(len); //set length (using setLength method)
    livingRoom.setWidth(wid); //set width (using setWidth method)

    //display results with one decimal place
    cout << fixed << setprecision(1); 

    //output for kitchen demensions by getting and displaying length, width, and area
    cout << "\nKitchen Dimensions: " << kitchen.getLength() << " x " << kitchen.getWidth() << ", with an area of "
         << kitchen.getArea() << " sq ft." << endl;

    //output for bedroom demensions by getting and displaying length, width, and area
    cout << "Bedroom Dimensions: " << bedroom.getLength() << " x " << bedroom.getWidth() << ", with an area of "
         << bedroom.getArea() << " sq ft." << endl;

    //output for living room demensions by getting and displaying length, width, and area
    cout << "Living Room Dimensions: " << livingRoom.getLength() << " x " << livingRoom.getWidth() << ", with an area of "
         << livingRoom.getArea() << " sq ft." << endl;

    //calculates and displays the area of all three rooms
    double totalArea = kitchen.getArea() + bedroom.getArea() + livingRoom.getArea(); //sum of room areas
    cout << "\nThe total of all three rooms is: " << totalArea << " sq ft." << endl; //output total

    return 0;
}