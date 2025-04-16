/*Elijah Kurland
April 16, 2025
This code takes in 2 strings as gadgets and then prints both. 
The swap function is then called to switch the order of the gadgets around.*/

#include <iostream> //used for input and output
#include <string> //used for string
#include <utility> //used for swap function
using namespace std;

//takes in 2 strings and prints both gadgets
void showGadgets(string gadget1, string gadget2){
    cout << "Gadget 1: " << gadget1 << ", " "Gadget 2: " << gadget2 << "\n";
}

int main(){
    //creates the 2 string variables
    string gadget1 = "Batarang";
    string gadget2 = "Grappling Hook";
    
    showGadgets(gadget1, gadget2);
    swap(gadget1, gadget2); //swap is called to switch the gadgets around.
    showGadgets(gadget1, gadget2); //prints swapped gadgets

    return 0;
}