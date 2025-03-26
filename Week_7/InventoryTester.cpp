#include <iostream> //for input and output streams
#include "Inventory.h" //uses inventory class
using namespace std;

int main() {
    //creates an inventory with space for 10 books
    Inventory inventory(10);

    //creates book objects with details and adds them to the inventory
    Book book1("013478796X", "Tony Gaddis", "Starting Out with Java", 4, "PE", 121.75);
    Book book2("0321409493", "John Lewis", "Java Software Solutions", 5, "AW", 94.00);
    Book book3("0134743350", "Harvey Deitel", "Java How to Program", 12, "PE", 134.84);
    Book book4("002360692X", "Richard Johns", "Algorithms", 1, "PH", 109.00);
    Book book5("1593276036", "Eric Matthes", "Python Crash Course", 1, "NS", 39.95);
    Book book6("0143067889", "Ray Kurzweil", "The Singularity is Near", 1, "PG", 17.70);

    //adds original books to inventory without printing the result
    inventory.addBook(book1);
    inventory.addBook(book2);
    inventory.addBook(book3);
    inventory.addBook(book4);
    inventory.addBook(book5);
    inventory.addBook(book6);

    //adds new books to inventory
    Book book7("0134444329", "Tony Gaddis", "Starting Out With Python", 4, "PE", 99.95);
    Book book8("0133582736", "Tony Gaddis", "Starting Out With Python", 3, "PE", 19.95);
    Book book9("013478796X", "Tony Gaddis", "Starting Out With Java", 4, "PE", 145.38);
    Book book10("1119056553", "Cay Horstmann", "Python for Everyone", 2, "WI", 98.38);
    Book book11("0134802217", "Tony Gaddis", "Starting Out With Java", 7, "PE", 188.95);
    Book book12("0134462017", "Tony Gaddis", "Starting Out With Java", 6, "PE", 58.50);

    //attempts to add new books to the inventory
    inventory.addBook(book7);
    inventory.addBook(book8);
    inventory.addBook(book9);
    inventory.addBook(book10);
    inventory.addBook(book11);
    inventory.addBook(book12);

    //prints the inventory after adding all books
    inventory.printInventory();

    //change prices for required books and prints the results
    inventory.changePrice("013478796X", 50.00);  // Gaddis book
    cout << "Changing price of 013478796X to $50.00" << endl;
    inventory.changePrice("0143067889", 9.95);   // Kurzweil book
    cout << "Changing price of 0143067889 to $9.95" << endl;
    inventory.changePrice("0134743350", 100.00); // Deitel book
    cout << "Changing price of 0134743350 to $100.00" << endl;

    //reprints the inventory after price changes
    inventory.printInventory();

    return 0;
};