/*Elijah Kurland
April 2, 2025
This code runs through all Fibonacci numbers up to 5000 using custom classes in header files (.h).*/

#include "PrimeNumberRange.h" //header file
#include "FibonacciIterator.h" //povides Fibonacci sequence iteration functionality
#include "FibonacciRange.h" //defines FibonacciRange class for generating Fibonacci numbers
#include <cstdio> //used for printf function

int main() {
	
	FibonacciRange range{ 5000 }; //create a Fibonacci range up to 5000
	const auto end = range.end(); //get the end iterator of the range

	for (auto x = range.begin(); x != end; ++x) { //iterate through the Fibonacci sequence

		const auto i = *x; //dereference iterator to get the Fibonacci number

		printf("%d ", i); //print the current Fibonacci number
	}

	return 0;
}