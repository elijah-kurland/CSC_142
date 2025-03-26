/*Elijah Kurland
March 26, 2025
This code relates to chapter 2 of the book by scanning the listings 
and marks which methods could be marked as constant. Where might auto be used?

- In Listing 2-20 the member function int get_year() can be marked becausecit doesn't
change the current state of the object. It is also a getter function which only returns.

- For auto, all the explicit types in every Listing can be swapped them with the keyword auto. 
For simple types such as int, double, and char, they can be written as explicit.
For more complicated types (Listing 2-1: unsigned short a = 0b10101010 unsigned long long d = 0xFFFFFFFFFFFFFFFF),
auto type deduction can be used to save time in typing it all out again.*/