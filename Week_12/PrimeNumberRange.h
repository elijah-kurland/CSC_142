/*Elijah Kurland
April 2, 2025
Implement a PrimeNumberRange class that can be used in a range exception
to iterate over all prime numbers less than a given value.Again, use a separate headerand source file.*/

#ifndef PRIMENUMBERRANGE_H
#define PRIMENUMBERRANGE_H
#include <cstddef>
using namespace std;

class PrimeNumberRange {
public:
    //constructor that initializes the range of prime numbers up to 'n'
    explicit PrimeNumberRange(int n)
    {
        //if n is less than 2, set current to -1
        if (n < 2)
            m_current = -1;
        else {

            m_capacity = n; //set the maximum value
            m_current = 2; //start from the first prime number
        }
    }

    //returns the current prime number
    int getCurrent() const {

        return m_current;
    }

    //finds and returns the next prime number in the range
    int next() {

        int i{}; //local variable to iterate through numbers
        for (i = m_current + 1; i <= m_capacity; ++i) {

            bool flag{ true }; //bool to check if 'i' is prime
            for (int j{ 2 }; j < i; ++j) //check if 'i' is divisible by any number less than 'i'

                if (i % j == 0) {

                    flag = 0; //if divisible, 'i' is not prime
                    break;
                }

            if (flag) { //if 'i' is prime, update current prime number

                m_current = i;
                break;
            }
        }
        //if the end of the range is reached, set current to -1 (no more primes)
        if (m_capacity < i)
            m_current = -1; 

        return m_current; //return the next prime (or -1 if no primes remain)
    }
    //operator overload to get the next prime number
    int operator++() {
        return next(); //returns the next prime number
    }

private:
    size_t m_capacity{}; //the maximum number in the range
    size_t m_current{}; //the current prime number in the range
};

#endif // PRIMENUMBERRANGE_H