#define INVENTORY_H
#include "Book.h" //uses book class
#include <iostream> //for input and output streams
using namespace std;

class Inventory {
private:
    Book* books; //pointer to array of book objects
    int nextEntry; //tracks where to add books
    int length; //max number of books the inventory can hold

public:
    //constructor that initializes the inventory
    Inventory(int size) {
        length = size; //sets max size
        nextEntry = 0; //initialize next index to zero
        books = new Book[length]; //array to hold books
    }

    //destructor that releases memory for book array
    ~Inventory() {
        delete[] books;
    }

    //method to add a book to the inventory
    //returns true if book is successfully added, false if inventory is full
    bool addBook(const Book& theBook) {
        if (nextEntry < length) { //checks for space
            books[nextEntry] = theBook; //adds book to array
            nextEntry++; //increments the next available index
            return true;
        }
        return false;
    }

    //method that changes the price of a book in the inventory
    //loops through all books and updates price (based on ISBN)
    void changePrice(const string& isbn, double newPrice) {
        for (int i = 0; i < nextEntry; i++) { //loops through books
            if (books[i].getISBN() == isbn) { //checks for match
                books[i].setPrice(newPrice); //updates price
                break; //exits after update
            }
        }
    }

    //method to print the details of all books in the inventory
    void printInventory() const {
        //prints the header row with formatted options (left align, set width, and right align)
        cout << "----------------------------------------------------------------------------------------\n";
        cout << left << setw(12) << "ISBN" 
                  << setw(15) << "AUTHOR" 
                  << setw(40) << "TITLE" 
                  << right << setw(5) << "ED" 
                  << setw(5) << "PUB" 
                  << setw(10) << "PRICE" << endl;

        //loops through all added books and prints the details with format options (left align, set width, right align, and decimal precision)
        for (int i = 0; i < nextEntry; i++) {
            cout << left << setw(12) << books[i].getISBN()
                      << setw(15) << books[i].getAuthor()
                      << setw(40) << books[i].getTitle()
                      << right << setw(5) << books[i].getEdition()
                      << setw(5) << books[i].getPublisher()
                      << fixed << setprecision(2) << setw(6) << "$" << books[i].getPrice()
                      << endl;
        }
        //separator line
        cout << "----------------------------------------------------------------------------------------\n";
    }
};