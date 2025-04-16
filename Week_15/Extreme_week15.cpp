/*Elijah Kurland
April 16, 2025
This code uses a tuple to make three objects: an integer, string, and boolean. These are then defined.
The tie function then "unpacks" the tuple and prints true or false if the riddle is solved.*/

#include <iostream> //used for input and output
#include <tuple> //used for tuple and tie
#include <string> //used for string
using namespace std;

tuple<int, string, bool> getRiddleInfo(){ //function returns int, string, and boolean
    return make_tuple(7, "What has roots as nobody sees, is taller than trees???", true); //creates the tuple and implements each value
}

int main(){
    //declares three variables to hold tuple values
    int riddleNumber; //integer
    string riddleText; //string
    bool solved; //boolean

    //unpacks the tuple and assigns each value to the corresponding variable.
    tie(riddleNumber, riddleText, solved) = getRiddleInfo();

    //prints the riddle number and text
    cout << "Riddle #" << riddleNumber << ": \"" << riddleText << "\"\n";

    //checks if the riddle is solved (true)
    cout << "Solved: " << (solved ? "Yes" : "No") << "\n";

    return 0;
}