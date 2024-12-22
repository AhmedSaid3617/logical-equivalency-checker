#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "Expression.h"
#include "Postfix.h"

using namespace std;

int main(){

    /* vector<string> inputs = {"a", "b", "c"};

    std::string input_expression = "b&c | a & ~(a|b)";
    std::string prefix_expr = infixToPrefix(input_expression); */

    Input in1 = Input();
    Input in2 = Input();
    Input in3 = Input();

    Or or_exp = Or(&in1, &in2);
    And and_exp = And(&or_exp, &in3);

    in1.set_input(false);
    in2.set_input(false);
    in3.set_input(false);

    if (or_exp.evaluate())
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    
    
    
}