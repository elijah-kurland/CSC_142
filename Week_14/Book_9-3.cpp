/*Elijah Kurland
April 14, 2025
This code impliments an all function with the following prototype:
template <typename Fn, typename In, typename Out>
constexpr bool all (Fn function, In* input, size_t length)*/

//CHAT WAS USED FOR HELP

#include <cstdint> //used for printf
#include <cstdio> //used for fixed width-integer types

//template function 'all' checks if all elements in input array satisfy a given condition
template <typename Fn, typename In>
constexpr bool all(Fn function, In* input, size_t length) {
	bool check = true; //starts by assuming all elements satisfy condition

	//loops over each element in array
	for (size_t index{}; index < length; index++) {
		check = function(input[index]); //applies predicate to current element

		//if any element fails the check, exit
		if (check == false) {
			break;
		}
	}
	return check; //returns true only if all elements passed check
}

int main() {
	//array of integers to test
	int data[]{100, 200, 300, 400, 500};
	size_t data_len = 5; //number of elements in array

	//uses 'all' function to check if all elements are greater than 100
	auto all_gt100 = all([](auto x) { return x > 100; }, data, data_len);

	//prints result of check
	if (all_gt100) 
		printf("All elements greater than 100. :]\n");
	else 
		printf("Check failed. :[\n");

	return 0;
}