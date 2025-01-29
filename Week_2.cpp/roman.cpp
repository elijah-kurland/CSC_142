/*Roman.cpp
Elijah Kurland
Jan. 29, 2025
*/

#include <iostream>
using namespace std;

int main(){
    int number;

    do {
        cout << "Please enter a number between 1 and 10: ";
        cin >> number;

        if (number < 1 || number > 10) {
        cout << "Please choose a different number withing 1-10\n";
        }
    } while (number <1 || number > 10);

    switch (number) {
        case 1:
            cout << "The Roman numeral for " << number << " is I\n";
            break;
        case 2:
            cout << "The Roman numeral for " << number << " is II\n";
            break;
        case 3:
            cout << "The Roman numeral for " << number << " is III\n";
            break;
        case 4:
            cout << "The Roman numeral for " << number << " is IV\n";
            break;
        case 5:
            cout << "The Roman numeral for " << number << " is V\n";
            break;
        case 6:
            cout << "The Roman numeral for " << number << " is VI\n";
            break;
        case 7:
            cout << "The Roman numeral for " << number << " is VII\n";
            break;
        case 8:
            cout << "The Roman numeral for " << number << " is VIII\n";
            break;
        case 9:
            cout << "The Roman numeral for " << number << " is IX\n";
            break;
        case 10:
            cout << "The Roman numeral for " << number << " is X\n";
            break;
    }
}