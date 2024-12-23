#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>

#include "Expression.h"
#include "Postfix.h"

using namespace std;

void get_truth_table(string in_expression, vector<bool> &result1, vector<vector<bool>> &inputs_matrix, vector<Expression *> &inputs);
bool is_satisfiable(vector<bool> &result1, vector<bool> &result2, vector<vector<bool>> &inputs_matrix, vector<Expression *> inputs);

int main()
{

    std::string input_expression1 = "a&~c|b";
    std::string input_expression2 = "~(b&c&a)";

    vector<bool> result1;
    vector<bool> result2;

    vector<vector<bool>> inputs_matrix1;
    vector<vector<bool>> inputs_matrix2;

    vector<Expression *> inputs1;
    vector<Expression *> inputs2;

    get_truth_table(input_expression1, result1, inputs_matrix1, inputs1);
    get_truth_table(input_expression2, result2, inputs_matrix2, inputs2);

    bool equivalent = true;
    bool satisfiable = false;
    if (result1.size() != result2.size())
    {
        equivalent = false;
    }
    else
    {
        for (int i = 0; i < result1.size(); i++)
        {
            if (result1[i] != result2[i])
            {
                equivalent = false;
                break;
            }
        }
    }

    // Check for equivalence.
    if (equivalent)
    {
        cout << "Expressions are equivalent." << endl;
    }
    else
    {
        cout << "Expressions not equivalent" << endl;
    }

    // Check satisfiablity.
    satisfiable = is_satisfiable(result1, result2, inputs_matrix1, inputs1);
    if (satisfiable)
    {
        return 0;
    }

    cout << "Expressions are not satisfiable." << endl;

    while (!satisfiable)
    {
        /* code */
    }
    
    
}

bool is_satisfiable(vector<bool> &result1, vector<bool> &result2, vector<vector<bool>> &inputs_matrix, vector<Expression *> inputs)
{
    for (int i = 0; i < result1.size(); i++)
    {
        if (result1[i] && result2[i])
        {
            cout << "Expressions are satisfiable." << endl;
            cout << "The inputs that make theses expressions satisfiable are:" << endl;
            for (int j = 0; j < inputs_matrix[i].size(); j++)
            {
                cout << ((Input *)inputs[j])->get_symbol() << ":" << inputs_matrix[i][j] << " ";
            }
            cout << endl;
            return true;
        }
    }
    return false;
}

void get_truth_table(string in_expression, vector<bool> &result1, vector<vector<bool>> &inputs_matrix, vector<Expression *> &inputs)
{
    std::string prefix_expr = infixToPrefix(in_expression);
    Expression my_expr = Expression(prefix_expr, inputs);
    std::sort(inputs.begin(), inputs.end(), Input::compare);
    bool output;

    cout << "      \t";
    for (int i = inputs.size() - 1; i >= 0; i--)
    {
        cout << ((Input *)inputs[i])->get_symbol() << "\t";
    }

    cout << endl;

    for (int i = 0; i < pow(2, inputs.size()); i++)
    {
        vector<bool> inner_inputs_array;
        cout << "Inputs:\t";
        for (int j = inputs.size() - 1; j >= 0; j--)
        {
            bool state = !(i & 1 << j);
            ((Input *)inputs[j])->set_input(state);
            inner_inputs_array.push_back(state);
            cout << state << "\t";
        }
        inputs_matrix.push_back(inner_inputs_array);
        output = my_expr.evaluate();
        result1.push_back(output);
        cout << "Outputs:\t";
        cout << output << endl;
    }
}