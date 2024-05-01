#include "Stack.h"
#include <cctype>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

bool isOperator(char ch) {
    return ch == '+' or ch == '-' or ch == '*' or ch == '/' or ch == '^';
}

bool isNumber(char ch) {
    return isdigit(ch) or ch == '.';
}

int priority(char op) {
    if (op == '+' or op == '-')
        return 1;
    if (op == '*' or op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

string infixToRPN(const string& infix) {
    stringstream output;
    Stack<char> operators;

    stringstream ss(infix);
    char ch;
    while (ss >> ch) {
        if (isNumber(ch)) {
            output << ch;
            while (ss.peek() and isNumber(ss.peek())) {
                ss >> ch;
                output << ch;
            }
            output << ' ';
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.isEmpty() and operators.top() != '(') {
                output << operators.top() << ' ';
                operators.pop();
            }
            operators.pop();
        } else if (isOperator(ch)) {
            while (!operators.isEmpty() and priority(operators.top()) >= priority(ch)) {
                output << operators.top() << ' ';
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.isEmpty()) {
        output << operators.top() << ' ';
        operators.pop();
    }

    return output.str();
}

double evaluateRPN(const string& rpn) {
    Stack<double> operands;

    stringstream ss(rpn);
    string token;
    while (ss >> token) {
        if (isdigit(token[0])) {
            operands.push(stod(token));
        } else if (isOperator(token[0])) {
            double operand2 = operands.top();
            operands.pop();
            double operand1 = operands.top();
            operands.pop();

            double result;
            switch (token[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = pow(operand1, operand2);
                    break;
            }
            operands.push(result);
        }
    }

    return operands.top();
}



