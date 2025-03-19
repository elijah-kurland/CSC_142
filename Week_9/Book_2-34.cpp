/*Elijah Kurland
March 17, 2025
Create a method on Calculator called int calculate(int a, int b).Upon invocation, 
this method should perform addition, subtraction, multiplication, or division 
based on its constructor argument and return the result.Experiment with different means 
of initializing Calculator instances.*/

#include <iostream>

//enum defines different mathematical operations
enum class Operation
{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

//calculator class that performs operations
class Calculator
{
public:
    //default constructor
    Calculator()
    {
        std::cout << "This should not be called.\n";
    }

    //constructor that initializes the calculator with an operation
    Calculator(Operation operation);

    //function to perform the calculation based on selected operation
    int calculate(int a, int b);

    //getter function to retrieve the current operation
    Operation get_operation()
    { 
        return m_operation; 
    }

private:
    Operation m_operation; //stores operation
};

//constructor definition to initialize the operation
Calculator::Calculator(Operation operation)
    : m_operation{operation} { }

//function to perform calculation based on stored operation
int Calculator::calculate(int a, int b)
{
    switch(get_operation())
    {
        case Operation::ADD: {
            return a + b;
        }

        case Operation::SUBTRACT: {
            return a - b;
        }

        case Operation::MULTIPLY: {
            return a * b;
        }

        case Operation::DIVIDE: {
            if (b == 0) {
                std::cerr << "Error: Division by zero.\n";
                return 0; 
            }
            return a / b;
        }

        default: {
            std::cout << "Not an operator I know of.\n";
            return 0; //ensures function always returns an int
        }
    }
}

int main()
{
    //creating calculator objects for different operations and performing calculations
    Calculator calc1 = { Operation::ADD }; //used for addition
    std::cout << "ADD: " << calc1.calculate(5, 6) << '\n';

    Calculator calc2{ Operation::SUBTRACT }; //used for subtraction
    std::cout << "SUBTRACT: " << calc2.calculate(6, 3) << '\n';

    Calculator calc3(Operation::MULTIPLY); //used for multiplication
    std::cout << "MULTIPLY: " << calc3.calculate(5, 5) << '\n';

    return 0;
}