/*Exams.cpp
Elijah Kurland
Jan. 29, 2025
This code asks the user to input three exam scores which will be calculated together to find the average score*/

#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::string name; //stores the name
    int score1, score2, score3; //stores the scores
    double average; //stores the average

    std::cout << "Please enter your name: "; //prompts user to enter name
    std::cin >> name; //takes name input

    std::cout << "Please enter three exam scores: "; //prompts user to enter scores
    std::cin >> score1 >> score2 >> score3; //takes scores input

    average = (score1 + score2 + score3) / 3.0; //calculates the average score

    std::cout << "\nWelcome Albright Student: " << name << std::endl; //prints name
    std::cout << "Your exam scores are: " << score1 << ", " << score2 << ", " << score3 << std::endl; //prints scores
    std::cout << "Your average score is: " << std::fixed << std::setprecision(2) << average << std::endl; 
    //prints average with setprecision adding 2 decimal places

    return 0;
}