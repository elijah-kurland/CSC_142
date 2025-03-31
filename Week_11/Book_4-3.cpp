/*Elijah Kurland
March 31, 2025
Implement a copy constructor and a copy assignment operator for TimerClass.
(the copies should share timestamp values)*/

#include <iostream>
#include <chrono>
using namespace std;

class TimerClass { //class measures the execute time

public:
    //constructor records the current timestamp when the object is created
    TimerClass()
        : m_timestamp{chrono::steady_clock::now() }
    {}

    //destructor calculates and prints the elapsed time when the object goes out of scope
    ~TimerClass() {
        auto current = chrono::steady_clock::now() - m_timestamp;
        cout << chrono::duration_cast<chrono::microseconds>(current).count();
        cout << " microseconds\n";
    }

    //copy constructor (copies TimerClass objects)
    TimerClass(const TimerClass &rhs)
        : m_timestamp{ rhs.m_timestamp }
    { }

    //copy assignment (handles assignment of TimerClass objects)
    TimerClass& operator=(const TimerClass &rhs) {
        if (this == &rhs) return *this; //avoids self-assignment

        m_timestamp = rhs.m_timestamp;

        return *this;
    }

private:
    chrono::steady_clock::time_point m_timestamp; //stores the start time
};