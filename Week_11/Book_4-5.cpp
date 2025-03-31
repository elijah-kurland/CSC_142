/*Elijah Kurland
March 31, 2025
Elaborate the TimerClass constructor to accept an additional const cahr* name parameter.
(when TimerClass is destructed and prints to stdout, include the name of the timer in the output)*/

#include <iostream>
#include <chrono>
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
    const char *m_name{}; //name for identifying timer output
};