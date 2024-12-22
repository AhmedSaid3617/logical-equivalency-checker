#ifndef POSTFIX_H
#define POSTFIX_H

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>

bool isOperator(char c);
int precedence(char op);
std::string infixToPrefix(const std::string &infix);

#endif