/*Elijah Kurland
March 31, 2025
Identify each method in the SimpleString class.*/

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <utility>
using namespace std;

//simple string class for managing C-style strings
class SimpleString {

public:
    SimpleString(); // default constructor
    explicit SimpleString(size_t max_size); //one-argument constructor
    ~SimpleString(); //destructor

    SimpleString(const SimpleString &rhs) noexcept; //copy constructor
    SimpleString& operator=(const SimpleString &rhs) noexcept; //copy assignment operator 

    SimpleString(SimpleString &&rhs) noexcept; //move constructor
    SimpleString& operator=(SimpleString &&rhs) noexcept; //move assignment operator

    void print(const char *tag) const
    { cout << tag << ": " << m_buffer << '\n'; } //print tag followed by the string buffer 

    bool append_line(const char *x); //appends a new line to the buffer.

private:
    size_t m_max_size; //maximum capacity of the string
    char  *m_buffer; //dynamically allocated buffer for the string
    size_t m_length; //current length of the stored string
};

//default constructor initializes with a default buffer size of 256
SimpleString::SimpleString()
    : m_max_size{ 256 },
      m_buffer{ new char[256] },
      m_length{} { }

//constructor initializes the buffer with a user-defined maximum size
SimpleString::SimpleString(size_t max_size)
    : m_max_size{ max_size },
      m_length{} {

    if (max_size == 0) throw runtime_error{ "Max size must be at least 1." };

    m_buffer = new char[max_size]; //allocate memory for the buffer
    m_buffer[0] = '\0'; //ensures the buffer is initially empty
}

//destructor releases allocated memory
SimpleString::~SimpleString()
{ delete[] m_buffer; }

//copy constructor creates a deep copy of another SimpleString object
SimpleString::SimpleString(const SimpleString &rhs) noexcept
    : m_max_size{ rhs.m_max_size },
      m_buffer{ new char[rhs.m_max_size] },
      m_length{ rhs.m_length } {

    strncpy(m_buffer, rhs.m_buffer, m_max_size); //copy the content from rhs
}

//copy assignment operator: Handles assigning one SimpleString object to another
SimpleString& SimpleString::operator=(const SimpleString &rhs) noexcept {

    if (this == &rhs) return *this; //prevent self-assignment
    
    delete[] m_buffer; //free existing memory
    m_buffer = new char[rhs.m_max_size]; //allocate new memory
    m_max_size = rhs.m_max_size;
    m_length = rhs.m_length;
    
    strncpy(m_buffer, rhs.m_buffer, m_max_size); //copy content from rhs
    
    return *this;
}

//move constructor transfers ownership of the buffer from rhs to the new object
SimpleString::SimpleString(SimpleString &&rhs) noexcept
    : m_max_size{ rhs.m_max_size },
      m_buffer{ rhs.m_buffer },
      m_length{ rhs.m_length } {

    //nullify the source object to prevent dangling pointers
    rhs.m_buffer = nullptr;
    rhs.m_max_size = 0;
    rhs.m_length = 0;
}

//move assignment operator transfers ownership of the buffer in an assignment operation
SimpleString& SimpleString::operator=(SimpleString &&rhs) noexcept {

    if (this == &rhs) return *this; //prevent self-assignment
    
    delete[] m_buffer; //free existing memory
    m_buffer = rhs.m_buffer;
    m_max_size = rhs.m_max_size;
    m_length = rhs.m_length;
    
    //nullify the source object
    rhs.m_buffer = nullptr;
    rhs.m_length = 0;
    rhs.m_max_size = 0;
    
    return *this;
}

//appends a new line of text to the buffer
bool SimpleString::append_line(const char *x) {

    const auto x_len = strlen(x); //get length of input string
    
    //check if there's enough space to add the new string and a newline character
    if (x_len + m_length + 2 > m_max_size) return false;
    
    strncpy(m_buffer + m_length, x, m_max_size - m_length); //append string
    m_length += x_len;
    m_buffer[m_length++] = '\n'; //add newline character
    m_buffer[m_length] = 0; //null-terminate the buffer
    
    return true;
}

int main() {

    try {
        //create two SimpleString objects with a max size of 50
        SimpleString a{ 50 };
        a.append_line("C++ is the better programming language!");
        
        SimpleString b{ 50 };
        b.append_line("No, Java is way better!");

        //print their contents
        a.print("a ");
        b.print("b ");
        
        //copy the contents of a into b using copy assignment
        b = a; 

        //print again to show that b now contains the same content as a
        a.print("a ");
        b.print("b ");
    }
    catch(const std::exception &e) {
        cerr << "exception: " << e.what() << '\n'; //handle standard exceptions
        return 1;
    }
    catch(...) {
        cerr << "unknown exception caught\n"; //handle any other unknown exceptions
        return 2;
    }

    return 0;
}