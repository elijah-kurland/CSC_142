#define BOOK_H

#include <string> //for strings
#include <iostream> //for input and output streams
#include <iomanip> //for input and output manipulators
using namespace std;

class Book {
public:
    //zero-argument constructor
    Book() : isbn(""), author(""), title(""), edition(0), publisher(""), price(0.0) {} //initializes variables with default values

    //parameter constructor
    Book(string isbn, string author, string title, int edition, string publisher, double price) //initializes variables with user values
        : isbn(isbn), author(author), title(title), edition(edition), publisher(publisher), price(price) {}

    //getter methods
    string getISBN() const { return isbn; }
    string getAuthor() const { return author; }
    string getTitle() const { return title; }
    int getEdition() const { return edition; }
    string getPublisher() const { return publisher; }
    double getPrice() const { return price; }

    //setter methods
    void setIsbn(const string& newIsbn) { isbn = newIsbn; }
    void setAuthor(const string& newAuthor) { author = newAuthor; }
    void setTitle(const string& newTitle) { title = newTitle; }
    void setEdition(int newEdition) { edition = newEdition; }
    void setPublisher(const string& newPublisher) { publisher = newPublisher; }
    void setPrice(double newPrice) { price = newPrice; }

    //method to print Book details
    void printBook() const {
        //prints with different format options (left align, set width, and right align)
        cout << left << setw(12) << isbn
                  << setw(15) << author
                  << setw(40) << title
                  << right << setw(5) << edition
                  << setw(5) << publisher
                  << "$" << fixed << setprecision(2) << setw(9) << price
                  << endl;
    }

    //private member variables to store book details
private:
    string isbn;
    string author;
    string title;
    int edition;
    string publisher;
    double price;
};