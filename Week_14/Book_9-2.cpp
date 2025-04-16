/*Elijah Kurland
April 14, 2025
This code accepts an arbitrary number of command line arguments, 
counts the length in characters, and prints a histogram of the argument length distribution.*/

//CHAT WAS USED FOR HELP

#include <cstdint> //used for printf
#include <cstdio> //used for fixed-width integer types

int main(int argc, char** argv) {
	//loops over each command-line argument starting from 1
	for (int i = 1; i < argc; i++) {
		size_t index{}; //resets index for each argument
		int count{}; //resets character count

		//counts number of characters in current argument
		while (argv[i][index]) {
			++count;
			++index;
		}

		//prints a line of asterisks equal to number of characters in argument
		printf("Argument #%d: ", i);
		for (int k = 0; k < count; k++) {
			printf("*");
		}
		printf("\n");
	}
    return 0;
}