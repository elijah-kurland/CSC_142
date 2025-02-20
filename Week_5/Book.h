#define BOOK_H

#include <string> //for using string class
#include <iostream> //for input and output
#include <iomanip> //used for formatting

class Book {
//stores private variables for books
private: 
    std::string codeNum;
    std::string author;
    std::string title;
    int edition;
    std::string pubCode;
    double price;

public:
    //constructor to initialize the Book object with values
    Book(std::string cn, std::string au, std::string ti, int ed, std::string pc, double pr) {
        //assigns book information
        codeNum = cn;
        author = au;
        title = ti;
        edition = ed;
        pubCode = pc;
        price = pr;
    }

    //getters that retrieve private values
    std::string getTitle() const {
        return title;
    }

    std::string getAuthor() const {
        return author;
    }

    double getPrice() const {
        return price;
    }

    int getEdition() const {
        return edition;
    }

    std::string getISBN() const {
        return codeNum;
    }

    std::string getPubCode() const {
        return pubCode;
    }

    //setter that allows for price change
    void changePrice(double newPrice) {
        price = newPrice; //changes book price to the new value
    }

    //method that displays information about the book
    void displayBookInfo() const {
        //formatting options
        std::cout << std::left
                  << std::setw(13) << codeNum
                  << std::setw(15) << author
                  << std::setw(45) << title.substr(0, 45)  // truncating long titles
                  << std::setw(5) << edition
                  << std::setw(5) << pubCode
                  << std::setw(10) << "$ " << std::fixed << std::setprecision(2) << price
                  << std::endl;
    }
};