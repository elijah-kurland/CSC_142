/*Elijah Kurland
March 31, 2025
This code creates a struct TimerClass. It records the current time in a field timestamp.*/

#include <chrono>
using namespace std;

class TimerClass { //class measures the execute time
    
public:
    //constructor records the current timestamp when the object is created
    TimerClass()
        : m_timestamp{ chrono::steady_clock::now() }
    { }

private:
    chrono::steady_clock::time_point m_timestamp; //stores the start time
};