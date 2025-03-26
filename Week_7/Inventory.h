#define INVENTORY_H
#include "Book.h" //uses the Book class
#include <iostream> //for input and output streams
#include <iomanip>  //for formatting
using namespace std;

class Inventory {
private:
    Book* books; //pointer to an array of Book objects
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
    //returns true if the book is successfully added and false if inventory is full or the book already exists
    bool addBook(const Book& theBook) {
        //checks for room in the inventory
        if (nextEntry >= length) {
            cout << "ERROR adding this book: " << theBook.getISBN() << endl;
            return false;
        }
        
        //checks if the book already exists in the inventory (ISBN)
        for (int i = 0; i < nextEntry; i++) {
            if (books[i].getISBN() == theBook.getISBN()) {
                cout << "ERROR adding this book: " << theBook.getISBN() << endl;
                return false;
            }
        }

        //add the new book to the inventory
        books[nextEntry] = theBook;
        nextEntry++;
        return true;
    }

    //method to change the price of a book in the inventory
    void changePrice(const string& isbn, double newPrice) {
        for (int i = 0; i < nextEntry; i++) {
            if (books[i].getISBN() == isbn) {
                books[i].setPrice(newPrice);
                break;
            }
        }
    }

    //method to print the details of all books in the inventory
    void printInventory() const {
        cout << "-------------------------------------------------------------------------------------------\n";
        cout << "ISBN        AUTHOR         TITLE                                        ED  PUB     PRICE\n";

        //loop through all added books and print their details with formatted options (left align, set width, right align, set precision)
        for (int i = 0; i < nextEntry; i++) {
            cout << left << setw(12) << books[i].getISBN()
                      << setw(15) << books[i].getAuthor()
                      << setw(42) << books[i].getTitle()
                      << right << setw(5) << books[i].getEdition()
                      << setw(5) << books[i].getPublisher()
                      << fixed << setprecision(2) << setw(6) << "$" << books[i].getPrice()
                      << endl;
        }

        cout << "-------------------------------------------------------------------------------------------\n"; //divider line
    }
};