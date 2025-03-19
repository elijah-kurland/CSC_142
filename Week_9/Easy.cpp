/*Elijah Kurland
March 17, 2025
This code will prompt the user for a name and age. Then it will calculate the approximate days that make up the years.*/

#include <iostream> //for input and output streams
#include <string> //for using strings

int main() {
    //declare variables name and age
    std::string name;
    int age;

    //prompts user for name
    std::cout << "Enter your name: ";
    std::cin >> name;

    //prompts user for age
    std::cout << "Enter your age: ";
    std::cin >> age;

    //calculates the number of days compared to the given age
    int age_in_days = age * 365;

    //prints the user's name, age, and the approximate days
    std::cout << "\nHello, " << name 
              << "! You are approximately " 
              << age_in_days
 << " days old." << std::endl;

    return 0;
}