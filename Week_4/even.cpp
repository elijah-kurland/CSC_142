/*Even.cpp
Elijah Kurland
Feb. 10, 2025
This program generates 1000 random numbers and calculates how many of them are even and how many are 
odd by doing quick math to see if the remainder is zero or not.
Each generation will give different numbers.*/

#include <iostream>
using namespace std;

bool isEven(int num){ //true and false method that checks to see if a number is even or odd
    return num % 2 == 0; //returns the even numbers
}

int main(){
    srand(time(0)); //adds a timer in seconds that is always refreshing (0)

    int even_numbers = 0; //stores the even numbers
    int odd_numbers = 0; //stores the odd numbers
    const int total_numbers = 1000; //tells the code that the total number is 1000

    for (int i = 0; i < total_numbers; i++) { //checks to see if i is less than 1000 and keeps running until it isn't. Increments by one each time it runs
        int random_num = rand() % 101; //generates a random integer within the range 0-100
        if (isEven(random_num )) {
            even_numbers++; //evens get incremented by 1 each time
        } else {
            odd_numbers++; //odds get incremented by 1 each time
        }
    }
    
    cout << "\033[37mTotal Numbers: " << total_numbers << endl; //prints the total numbers in white
    cout << "\033[34mEven Numbers: " << even_numbers << endl; //prints the even numbers in blue
    cout << "\033[31mOdd Numbers: " << odd_numbers << endl; //prints the odd numbers in red

    return 0;
}