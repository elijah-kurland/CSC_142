/*Elijah Kurland
March 26, 2025
Add an Element* previous to Listing 3-9 to make a doubly linked list. Add an insert_before method to Element.
Traverse the list from front to back, then from back to front, using two separate for loops. 
Print the operating_number inside each loop*/

#include <iostream>
using namespace std;

//class representing node (Link) in a doubly linked list
class Link
{
public:
    short m_operation_number; //stores the operation number of the node

    Link(const short on); //constructor to initialize node
    void insert_after(Link* new_element); //inserts a node after the current node
    Link* insert_before(Link* new_element); //inserts a node before the current node

    void traverse_forward(Link* main_trooper) const; //traverses and prints list forward
    void traverse_backwards(Link* main_trooper) const; //traverses and prints list backward

    //getter methods for next and previous pointers
    Link* get_next() const { return next; }
    Link* get_prev() const { return prev; }

private:
    Link *next; //pointer to the next node
    Link *prev; //pointer to the previous node
};

//constructor initializes a node with given value and null pointers
Link::Link(const short on)
    : m_operation_number{on},
      next{nullptr},
      prev{nullptr} { }

//inserts a new node after the current node
void Link::insert_after(Link* new_element)
{
    if (!new_element) return; //do nothing if new_element is null
    if (!this) return; //do nothing if current node is null

    new_element->prev = this; //set the previous pointer of the new node to current node
    
    if (this->next)
        this->next->prev = new_element; //update next node's previous pointer if it exists

    new_element->next = this->next; //link new node to next node
    this->next = new_element; //update current node's next pointer
}

//inserts a new node before the current node and returns the new node as the new head
Link* Link::insert_before(Link* new_element)
{
    if (!new_element)  return this; //if new_element is null, return current node
    if (!this)         return new_element; //if current node is null, return new_element as new head

    new_element->next = this; //set new node's next to current node

    if (this->prev)
        this->prev->next = new_element; //update previous node's next pointer if it exists

    new_element->prev = this->prev; //link new node to previous node
    this->prev = new_element; //update current node's previous pointer

    return new_element; //return new node as the new head
}

//traverses and prints the list forward
void Link::traverse_forward(Link* main_trooper) const
{
    if(!main_trooper) return;

    const Link* curr{main_trooper};
    cout << "{ ";
    while(curr) 
    {
        cout << curr->m_operation_number;
        if(curr = curr->get_next()) //move to next node and print separator if not null
            cout << " <=> ";
    }
    cout << " }\n";
}

//traverses and prints the list backward
void Link::traverse_backwards(Link *main_trooper) const
{
    if(!main_trooper) return;

    const Link* tail{main_trooper};

    //move to the last node in the list
    while(tail->get_next())
        tail = tail->get_next();

    cout << "{ ";
    while(tail)
    {
        cout << tail->m_operation_number;
        if(tail = tail->get_prev()) //move to previous node and print separator if not null
            cout << " <=> ";
    }
    cout << " }\n";
}

int main()
{
    //create initial node with value 2187
    Link *main_trooper{new Link{2187}};
    
    //insert nodes making each new node the head
    main_trooper = main_trooper->insert_before(new Link{421});
    main_trooper = main_trooper->insert_before(new Link{500});
    main_trooper = main_trooper->insert_before(new Link{16});
    main_trooper = main_trooper->insert_before(new Link{348});

    //insert a node after the current head (348)
    main_trooper->insert_after (new Link{111});

    //print the list in forward and backward order
    main_trooper->traverse_forward(main_trooper);
    main_trooper->traverse_backwards(main_trooper);

    return 0;
}