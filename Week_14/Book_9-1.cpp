/*Elijah Kurland
April 14, 2025
This code implements a fold function with the following prototype:
template <typename Fn, typename In, typename Out>
constexpr Out fold (Fn function, In* input, size_t length, Out initial)*/

//CHAT WAS USED FOR HELP

#include <cstdio> //used for printf
#include <cstdint> //used for fixed-width integer types

//fold - implements a generic reduction operation over an array.
//Fn - function type to apply to each element.
//In* - the input array type.
//Out - the output/accumulator type.
template<typename Fn, typename In, typename Out>
constexpr Out fold(Fn function, In* input, size_t length, Out initial) {
	if (length == 0) {
		//if array is empty, return initial value
		return initial;
	} else {
		//loop through the array and apply folding function
		for (size_t index = 0; index < length; index++) {
			initial = function(input[index], initial);
		}
		return initial;
	}
}

int main() {
	//initializes array of integers
	int data[]{ 100, 200, 300, 400, 500 };
	size_t data_len = 5;

	//use 'fold' to sum the elements of the array
	auto sum = fold([](auto x, auto y) { return x + y; }, data, data_len, 0);
	printf("Sum: %d\n", sum);  //output: Sum: 1500

	//use 'fold' to find maximum value in array
	auto maximum = fold([](auto x, auto y) { 
		auto result = x >= y ? x : y; 
		return result; 
	}, data, data_len, data[1]);
	printf("Maximum: %d\n", maximum);  //output: Maximum: 500

	//use 'fold' to find minimum value in array
	auto minimum = fold([](auto x, auto y) { 
		auto result = x <= y ? x : y; 
		return result; 
	}, data, data_len, data[1]);
	printf("Minimum: %d\n", minimum);  //output: Minimum: 100

	//counts how many numbers in array are over 200
	int count{}; //count of values over 200
	int index{}; //tracks current index in array
	auto over200 = fold([&](auto x, auto y) {
		if (x > 200) ++count; //increments count if condition met
		return data[index++]; //returns current value then moves to next
	}, data, data_len, 200);
	printf("Count over 200: %d\n", count); //output: Count over200: 3

    return 0;
}