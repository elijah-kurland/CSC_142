/*Elijah Kurland
March 26, 2025
Reimplement listing 3-11 using not explicit types. This code shows that when a reference is assigned a new value, 
the original variable it refers to is also updated.*/

#include <cstdio>
using namespace std;

int main()
{
    auto original = 100; //declares an integer variable 'original' and initialize it with 100
    auto &original_ref = original; //creates a reference 'original_ref' that refers to 'original'

    //print the values of 'original' and its reference
    printf("Original: %d\n", original);
    printf("Reference: %d\n", original_ref);

    auto new_value = 200; //declares a new integer variable 'new_value' and initialize it with 200
    original_ref = new_value; //assigns 'new_value' to 'original_ref', which modifies 'original'

    //print the updated values
    printf("Original: %d\n", original); 
    printf("New Value: %d\n", new_value); 
    printf("Reference: %d\n", original_ref);

    return 0;
}