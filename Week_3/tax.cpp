/*Tax.cpp
Elijah Kurland
Feb. 3, 2025
This program gets information about a purchase from the user, 
calculates the tax and total purchase amount, 
and displays the results.*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const double sales_tax = 0.06; //stores the sales tax number
    bool keep_going = true; //stores the true or false for the program to continue running
    string description; //stores description of purchase
    string cost_string; //stores the cost of the purchase
    double cost;
    string user_response; //stores the user's responses to the questions

    //checks to make sure the user wants to continue the tax calculation
    while (keep_going) {
        cout << "Please enter your purchase (or type 'quit' to exit): "; //prompts the user to enter their purchase or quit
        getline(cin, description);
        if (description == "quit") {
            break; 
        }

        //prompts the user to enter the cost of their purchase
        do {
            cout << "Please enter the cost of the purchase: ";
            getline(cin, cost_string);

            //checks to make sure the user entered a positive number and a number at all
            try {
                cost = stod(cost_string);
                if (cost < 0) {
                    cout << "The cost cannot be negative. Please enter a positive amount.\n";
                }
            } catch (const invalid_argument) {
                cout << "Invalid input. Please enter a numeric value.\n"; //tells the user to enter a positive number
            }
        } while (cost < 0);

        //calculates the cost with tax
        double totalCost = cost + (cost *sales_tax);
        cout << fixed << setprecision(2); //makes sure to only print two spaces after the decimal point
        cout << "Purchase: " << description << " | Cost: $" << cost << " | Total with tax: $" << totalCost << endl; //prints a summary of the purchase

        //asks the user if they would like to make another purchase
        cout << "Would you like to enter another purchase? (yes/no): ";
        getline(cin, user_response);
        if (user_response != "yes") { //checks if the user typed yes to continue adding items purchased
            keep_going = false;
        }
    }

    return 0;
}