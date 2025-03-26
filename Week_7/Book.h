#define BOOK_H

#include <string> // for strings
#include <iostream> // for input and output streams
#include <iomanip> // for input and output manipulators
using namespace std;

class Book {
public:
    //zero-argument constructor
    Book() : isbn(""), author(""), title(""), edition(0), publisher(""), price(0.0) {}

    //parameter constructor
    Book(string isbn, string author, string title, int edition, string publisher, double price)
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

    //prints with different format options (left align, set width, right align, and set precision)
    void printBook() const {
        cout << left << setw(12) << isbn
             << setw(15) << author
             << setw(40) << title
             << right << setw(5) << edition
             << setw(5) << publisher
             << "$" << fixed << setprecision(2) << setw(9) << price
             << endl;
    }

    //overloading << operator to allow printing using stream output
    friend ostream& operator<<(ostream& output, const Book& book) {
        output << left << setw(12) << book.isbn
               << setw(15) << book.author
               << setw(40) << book.title
               << right << setw(5) << book.edition
               << setw(5) << book.publisher
               << "$" << fixed << setprecision(2) << setw(9) << book.price;
        return output;
    }

    //overloading == operator to compare objects based on (ISBN)
    friend bool operator==(const Book& mainBook, const Book& otherBook) {
        return mainBook.isbn == otherBook.isbn;
    }

    //lists all private variables
private:
    string isbn;
    string author;
    string title;
    int edition;
    string publisher;
    double price;
};