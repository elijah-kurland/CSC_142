#include <iostream>
#include <ctime>
using namespace std;

//function to check if a number is prime
bool isPrime(int num){ //determines whether a given int num is a prime number
    if (num < 2) return false; //numbers below 2 are not considered prime numbers and are returned as false
    for (int i = 2; i * i <= num; i++){ //checks if num is evenly divisible by 2
        if (num % i == 0) return false; //if the number is divided by the given and has a remainder of 0, then it is not prime
    }
    return true; //executes if the nummber given has made it past the other checkers
}

//function to calculate factorial
double factorial (int num){ //returns a double because int cannot store very large numbers
    if (num == 0) return 1; //factorial of 0 is 1
    double result = 1; //multiplies by 1 so as to not change the product (starting point for the multiplication)
    for (int i = 1; i <= num; i++){ //for loop that starts at 1 and counts up by 1
        result *= i; //multiplies by i at each step
    }
    return result;
}

//main method for calculating and printing out the results
int main(){
    srand (time(0)); //gives current time to make sure the number generated is different each run
    char choice; //character choice that is stored to check if the user wants to repeat the process

    do {
        int num = rand() % 50; //generates a random number from 0-49
        cout << "Generated number: " << num << endl; //prints the generated number
        
        if (isPrime(num)){ //checks for prime number
            cout << num << " is a prime number." << endl; //prints if the number was prime
            cout << "Factorial of " << num << " is: " << factorial(num) << endl; //prints the factorial only if the number was prime
        } else {
            cout << num << " is not a prime number." << endl; //prints message is number is not prime
        }

        cout << "Do you want to try again? (y/n)" << endl; //prompts the user to go again
        cin >> choice; //takes in the choice and stores it in the char
    } while (choice == 'y'); //completes the do-while loop by repeating the steps if the users types 'y'

    cout << "Thanks for trying!" << endl; //prints out statement if user types 'n' and shuts the program
    return 0;
}