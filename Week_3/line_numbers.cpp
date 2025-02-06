/*Line_Numbers.cpp
Elijah Kurland
Feb. 5, 2025
This code takes the txt file and formats it with five spaces, a period, and an extra space for each line of text.*/

#include <iostream> //used for input and output
#include <fstream> //handles ifstream for reading and ofstream for writing
#include <string> //handles text strings
#include <format> //enables formatting function

using namespace std;

int main() {
    string text; //stores each line of the input file
    string text_input; //stores the input file
    string text_output; //stores the output file
    ofstream outFile; //writes to the output

    //prompts the user for the file name to be read
    cout << "Please enter the name of your input text file: ";
    cin >> text_input;

    ifstream inFile(text_input);

    //prompts the user for the file name to be written
    cout << "Please enter the name of your output text file: ";
    cin >> text_output;
    outFile.open(text_output);

    int line_number = 1;
    while (getline(inFile, text)) { //reads each line from the input file
        outFile << format("{:5}. {}\n", line_number, text); //alligns, adds a period, and a space
        line_number++; //loops through the lines to make sure each one is added
    }

    //closes both input and output files (keeps things safe)
    inFile.close();
    outFile.close();
    
    cout << "File processed successfully!" << endl;

    return 0;
}
