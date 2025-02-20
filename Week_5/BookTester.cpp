#include "Book.h" //includes the header file

int main() {
    //creates book objects with details
    Book book1("013478796X", "Tony Gaddis", "Starting Out With Java: From Control Structures through Data Structures", 4, "PE", 118.30);
    Book book2("0321409493", "John Lewis", "Java Software Solutions: Foundations of Program Design", 5, "AW", 94.05);
    Book book3("0134743350", "Harvey Deitel", "Java How to Program, Early Objects", 12, "PE", 134.84);

    //prints the book information with formatting options
    std::cout << "-----------------------------------------------------------------------------------------\n";
    std::cout << std::left
              << std::setw(13) << "ISBN"
              << std::setw(15) << "AUTHOR"
              << std::setw(45) << "TITLE"
              << std::setw(5) << "ED"
              << std::setw(5) << "PUB"
              << std::setw(10) << "PRICE"
              << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------\n";

    //displays the information using the displayBookInfo method
    book1.displayBookInfo();
    book2.displayBookInfo();
    book3.displayBookInfo();

    //changes the price for each book
    book1.changePrice(145.68);
    book2.changePrice(117.79);
    book3.changePrice(59.99);

    //informs the user of the price changes
    std::cout << "\nChanging book1 price from $ 118.30 to $ 145.68\n";
    std::cout << "Changing book2 price from $ 94.05 to $ 117.79\n";
    std::cout << "Changing book3 price from $ 134.84 to $ 59.99\n";

    //prints headers with updated information
    std::cout << "-----------------------------------------------------------------------------------------\n";
    book1.displayBookInfo();
    book2.displayBookInfo();
    book3.displayBookInfo();
    std::cout << "-----------------------------------------------------------------------------------------\n";

    return 0;
}