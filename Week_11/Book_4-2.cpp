/*Elijah Kurland
March 31, 2025
In the destructor of TimerClass, record the current time and subtracts the time at construction.
(the time is roughly the age of the timer)*/

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

private:
    chrono::steady_clock::time_point m_timestamp; //stores the start time
};