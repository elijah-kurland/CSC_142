/*Elijah Kurland
March 31, 2025
Create a timer and move it into a function that performs some commputationally intensive operation.
(verify that the timer behaves as expected)*/

#include <iostream>
#include <chrono>
#include <exception>
#include <limits>
using namespace std;

class TimerClass { //class measures the execute time

public:
    //constructor records the current timestamp when the object is created
    TimerClass(const char *name)
        : m_timestamp{chrono::steady_clock::now() },
          m_name{ name } { }

    //destructor calculates and prints the elapsed time when the object goes out of scope
    ~TimerClass() {
        auto current = chrono::steady_clock::now() - m_timestamp;
        cout << m_name << chrono::duration_cast<chrono::microseconds>(current).count();
        cout << " microseconds\n";
    }

    //copy constructor (copies TimerClass objects)
    TimerClass(const TimerClass &rhs) noexcept
        : m_timestamp{ rhs.m_timestamp },
          m_name{ rhs.m_name } { }

    //copy assignment (handles assignment of TimerClass objects)
    TimerClass& operator=(const TimerClass &rhs) noexcept {

        if (this == &rhs) return *this;

        m_timestamp = rhs.m_timestamp;
        m_name = rhs.m_name;

        return *this;
    }

    //move constructor (allows for moving TimerClass objects)
    TimerClass(TimerClass &&rhs) noexcept
        : m_timestamp{ rhs.m_timestamp },
          m_name{ rhs.m_name } { }

    //move assignment (moves a TimerClass object)
    TimerClass& operator=(TimerClass &&rhs) noexcept {
        if (this == &rhs) return *this; //avoids self-assignment
        m_timestamp = rhs.m_timestamp;
        m_name = rhs.m_name;
        return *this;
    }

private:
    chrono::steady_clock::time_point m_timestamp; //stores the start time
    const char *m_name; //name for identifying timer output
};

//computes sequence 'n' numbers
void fibonacci(long long fib1, long long fib2, long long n, TimerClass &&timer) {
    if(n < 2) throw runtime_error{"n must be at least 2."}; //ensures valid input

    cout << fib1 << ", " << fib2 << ", ";
    for(auto i{fib2}; i < n; ++i) {

        long long temp{fib1+fib2};

        if(temp < 0) throw runtime_error{"int overflow!"}; //checks for integer overflow

        fib1 = fib2;
        fib2 = temp;

        cout << fib2;
        if(i < n-1) cout << ", "; //only prints comma if it is not the last number
    }
    cout << "\n\n";
}

int main() {

    try {
        
        cout << "How many fibonacci numbers do you want to see computed?\n";
        cout << "Enter -1 to quit.\n";
        
         while(true) {

            cout << "> "; 
            long long n{};
            cin >> n;

            if(cin) {

                if(n == -1) break; //exit program in user input is -1

                cout << "fibonacci(" << n << "): ";
                fibonacci(1LL, 2LL, n, TimerClass{"Time: "}); cout << "\n\n";
            }
            else if(cin.fail()) {

                cin.clear(); //reset the stream state
                cin.ignore(numeric_limits<int>::max(), '\n'); //clear input buffer

                cout << "Sorry, you didn't enter a number. Try again\n";
            }
            else {

                throw runtime_error{"bad input"}; //handles unexpected input
            }
            
        }
    }
    catch(const exception &e) {

        cerr << "exception: " << e.what() << '\n'; //handles standard exceptions
        return 1;
    }
    catch(...) {

        cerr << "unknown exception caught\n"; //catches other/unkown exceptions
        return 2;
    }
    
    return 0;
}