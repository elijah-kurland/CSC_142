#include <iostream> //for input and output streams
#include "Inventory.h" //uses inventory class

int main() {
    //creates an inventory with space for 10 books
    Inventory inventory(10);

    //create book objects with details and add them to the inventory
    Book book1("013478796X", "Tony Gaddis", "Starting Out with Java", 4, "PE", 121.75);
    Book book2("0321409493", "John Lewis", "Java Software Solutions", 5, "AW", 94.00);
    Book book3("0134743350", "Harvey Deitel", "Java How to Program", 12, "PE", 134.84);
    Book book4("002360692X", "Richard Johns", "Algorithms", 1, "PH", 109.00);
    Book book5("1593276036", "Eric Matthes", "Python Crash Course", 1, "NS", 39.95);
    Book book6("0143067889", "Ray Kurzweil", "The Singularity is Near", 1, "PG", 17.70);

    //adds books to inventory
    if (inventory.addBook(book1)) std::cout << "Added: " << book1.getISBN() << std::endl;
    if (inventory.addBook(book2)) std::cout << "Added: " << book2.getISBN() << std::endl;
    if (inventory.addBook(book3)) std::cout << "Added: " << book3.getISBN() << std::endl;
    if (inventory.addBook(book4)) std::cout << "Added: " << book4.getISBN() << std::endl;
    if (inventory.addBook(book5)) std::cout << "Added: " << book5.getISBN() << std::endl;
    if (inventory.addBook(book6)) std::cout << "Added: " << book6.getISBN() << std::endl;

    //prints the original inventory
    inventory.printInventory();

    //change prices for required books
    inventory.changePrice("013478796X", 50.00);  // Gaddis book
    inventory.changePrice("0143067889", 9.95);   // Kurzweil book
    inventory.changePrice("0134743350", 100.00); // Deitel book

    //reprint the inventory after price changes
    inventory.printInventory();

    return 0;
}