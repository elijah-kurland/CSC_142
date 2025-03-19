/*Elijah Kurland
March 17, 2025
Create a struct Calculator. It should have a single constructor that takesan Operation.*/

 enum class Operation
 {
     ADD,
     SUBTRACT,
     MULTIPLY,
     DIVIDE
 };
 
 class Calculator
 {
 public:
     Calculator(Operation operation);
 
 private:
     Operation m_operation;
 };