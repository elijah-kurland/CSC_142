#include <iostream>
int main(){
    std::string desc;
    std::cout << "Please enter a description of your car.";
    std::getline(std::cin, desc);
    std::cout << "Great Ride!" << std::endl;
}