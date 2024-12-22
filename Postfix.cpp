#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '|' || c == '&' || c == '~';
}

int precedence(char op) {
    if (op == '~') return 4; // Highest precedence for NOT
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    if (op == '&') return 0; // AND
    if (op == '|') return -1; // OR
    return -2; // Undefined precedence
}

std::string infixToPrefix(const std::string &infix) {
    std::string reversed = infix;
    std::reverse(reversed.begin(), reversed.end());
    
    for (char &c : reversed) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    std::stack<char> operators;
    std::string postfix = "";

    for (char c : reversed) {
        if (std::isalnum(c)) {
            postfix += c; // Append operand directly
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Remove '('
        } else if (isOperator(c)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    std::reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    std::string infix = "a&b|~(c&b)";
    std::cout << "Infix: " << infix << "\n";
    std::cout << "Prefix: " << infixToPrefix(infix) << "\n";
    return 0;
}
