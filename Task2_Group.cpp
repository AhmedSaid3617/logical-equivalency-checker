#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "Expression.h"

using namespace std;


vector<string> tokenize(string expression){
    std::vector<std::string> tokens;

    // Use stringstream to tokenize the string
    std::stringstream ss(expression);
    std::string word;

    while (ss >> word) {
        tokens.push_back(word);
    }

    return tokens;
}

int main(){
    tokenize("Hello sdj sak s");
    Input in1 = Input();
    Input in2 = Input();
    Input in3 = Input();

    Or or_exp = Or(&in1, &in2);
    And and_exp = And(&or_exp, &in3);

    in1.set_input(true);
    in2.set_input(false);
    in3.set_input(false);

    if (and_exp.evaluate())
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    
    
    
}