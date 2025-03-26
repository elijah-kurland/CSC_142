/*Elijah Kurland
March 26, 2025
Add a read_from and a write_to function to Listing 3-6. These functions should read or write 
to upper or lower as appropriate. Perform bounds checking to prevent buffer overflows.*/

#include <iostream>  
#include <iterator>  
using namespace std;

//function to write a character to a specified index in the array
void write_to(char *ptr, size_t len, const int index, char input)
{
    //check if the index is within bounds
    if(index < 0 || index > len - 1)
        cerr << "Invalid index at " << index << '\n'; //print error if index is out of range
    else                                                    
        ptr[index] = input; //assign the input character to the specified index
}

//function to read and print a character from a specified index in the array
void read_from(const char *ptr, size_t len, const int index)
{
    //check if the index is within bounds
    if(index < 0 || index > len - 1)
        cerr << "Invalid index at " << index << '\n'; //print error if index is out of range
    else
        cout << "ptr[" << index << "] = " << ptr[index] << '\n'; //print the character at the given index
}

int main()
{
    //declare and initialize character arrays
    char lower[] = "abc?e"; //array with '?' to be modified
    auto lower_len = size(lower); //get the size of the array

    char upper[] = "ABC?E"; //another array with a '?' character
    auto upper_len = size(upper); //get the size of the array

    //modify and read the character at index 3
    write_to(lower, lower_len, 3, 'd'); //change '?' to 'd' in the lower array
    read_from(lower, lower_len, 3); //print the modified character

    write_to(upper, upper_len, 3, 'D'); //change '?' to 'D' in the upper array
    read_from(upper, upper_len, 3); //print the modified character

    //print the final modified arrays
    cout << "lower: " << lower << '\n'; //output: lower: abcdE
    cout << "upper: " << upper << '\n'; //output: upper: ABCDE
}