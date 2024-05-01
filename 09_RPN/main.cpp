#include "RPN.h"

int main() {
    string infixExpression;
    cout << "Enter the expression in infix notation: ";
    getline(cin, infixExpression);

    string rpnExpression = infixToRPN(infixExpression);
    cout << "Expression in RPN: " << rpnExpression << endl;

    double rpnVal = evaluateRPN(rpnExpression);
    cout << "Result: " << rpnVal;
    return 0;
}