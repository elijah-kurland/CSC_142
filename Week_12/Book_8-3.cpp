/*Elijah Kurland
April 2, 2025
Integrate PrimeNumberRange into Listing 8-27, adding another loop 
that generates all prime numbers less than 5000*/

#include "FibonacciIterator.h" //provides Fibonacci sequence iteration functionality
#include "PrimeNumberRange.h" // defines functionality for iterating through prime numbers
#include "FibonacciRange.h" // defines FibonacciRange class for generating Fibonacci numbers
#include <iostream> //used for input and output
using namespace std;

int main() {
    //print Fibonacci numbers up to 5000
    cout << "Fibonacci: ";
    for (const auto &i : FibonacciRange{5000}) { //iterates through Fibonacci numbers
        cout << i << ' '; //prints each Fibonacci number
    }
    cout << "\n\n";

    //initialize PrimeNumberRange to find prime numbers up to 5000
    PrimeNumberRange prime{5000};

    cout << "Prime: ";
    cout << prime.getCurrent() << ' '; //print the first prime number

    //iterates through prime numbers using PrimeNumberRange
    while (true) {
        int n{++prime}; //get the next prime number

        if (n < 0) //check if the range is exhausted (negative value signals end)
            return true; 

        cout << n << ' '; //print each prime number
    }

    return 0;
}