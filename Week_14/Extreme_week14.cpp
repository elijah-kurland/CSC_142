/*Elijah Kurland
April 14, 2025
This code creates a string encoder that translates letters to numbers with force bonus points. 
It also encodes messages with a Caesar cipher (like shifting text forward in the alphabet).*/

#include <iostream> //used for input and output
#include <string> //used for string
#include <cctype> //used for toupper
using namespace std;

//converts a letter to its alphabetical position (A=1, B=2, ect)
int decode_char(char letter) {
    return toupper(letter) - 'A' + 1;
}

//overloaded version of decode_char that adds a bonus value ("Force bonus")
int decode_char(char letter, int bonus) {
    return decode_char(letter) + bonus;
}

//decodes entire message by summing the values of its characters (using decode_char)
int decode_message(const string& message, int index = 0) {
    if (index >= message.size()) return 0; //end of string
    return decode_char(message[index]) + decode_message(message, index + 1);
}

//shifts each alphabetic character in a message forward by a fixed amount (Caesar cipher)
//non-alphabetic characters are left unchanged
string yoda_shift(const string& msg, int shift = 2) {
    string result;
    for (char c : msg) {
        if (isalpha(c)) {
            //determine base ('A' for uppercase, 'a' for lowercase)
            char base = isupper(c) ? 'A' : 'a';
            //shift character, wrap around alphabet using modulo
            result += static_cast<char>((c - base + shift) % 26 + base);
        } else {
            //keep non-alphabet characters unchanged
            result += c;
        }
    }
    return result;
}

int main() {
    //decode single character without and with bonus
    cout << "Yoda decoding 'C': " << decode_char('C') << "\n";
    cout << "With Force bonus +5: " << decode_char('C', 5) << "\n";

    //decode entire message by summing decoded values of characters
    cout << "Yoda message sum of 'ABC': " << decode_message("ABC") << "\n";

    //shift message by 2 characters forward (e.g., Caesar cipher)
    cout << "Yoda shifted message: " << yoda_shift("Hello Obi-Wan") << "\n";

    return 0;
}