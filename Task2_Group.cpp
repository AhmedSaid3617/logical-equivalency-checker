#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>

#include "Expression.h"
#include "Postfix.h"

using namespace std;

int main(){

    std::string input_expression = "a&(~b|c)";
    std::string prefix_expr = infixToPrefix(input_expression);
    vector<Expression*> inputs;

    Expression my_expr = Expression(prefix_expr, inputs);

    /* ((Input*)inputs[0])->set_input(false);
    ((Input*)inputs[1])->set_input(false);
    ((Input*)inputs[2])->set_input(false); */

    cout << "      \t";
    for (int i = inputs.size() -1; i >= 0; i--)
    {
        cout << ((Input*)inputs[i])->get_name() << "\t";
    }
    
    cout << endl;

    for (int i = 0; i < pow(2, inputs.size()); i++)
    {
        cout << "Inputs:\t";
        for (int j = inputs.size() -1; j >= 0; j--)
        {
            bool state = !(i & 1<<j);
            ((Input*)inputs[j])->set_input(state);
            cout << state << "\t";
        }

        cout << "Outputs:\t";
        cout << my_expr.evaluate() << endl;
    }


    /* Input in1 = Input();
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
    } */
    
    
    
}