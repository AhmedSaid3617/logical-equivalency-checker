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

    std::string input_expression1 = "(a&b) | (b|c)&(b&c) | ~(b&c)&(b&c)";
    std::string input_expression2 = "b&(a|c)";

    cout << "The input expressions must be in c/c++ form\n";
    cout << "Given example: (a&b) | (b|c)&(b&c) | ~(b&c)&(b&c)\n";
    cout << "Simplified version: b&(a|c)\n";
    cout << "Or you can try any two logical expressions.\n";
    cout << "The expressions can have any number of variables but must be an equal number\n";
    cout << "All variables must be exactly one character.\n";

    /* // Taking first string input
    std::cout << "Enter the first expression: ";
    std::getline(std::cin, input_expression1);

    // Taking second string input
    std::cout << "Enter the second expression: ";
    std::getline(std::cin, input_expression2); */

    vector<bool> result1;
    vector<bool> result2;

    vector<vector<bool>> inputs_matrix1;
    vector<vector<bool>> inputs_matrix2;

    vector<Expression *> inputs1;
    vector<Expression *> inputs2;
    
    cout << input_expression1 << endl;
    get_truth_table(input_expression1, result1, inputs_matrix1, inputs1);
    cout << "**********************\n" << input_expression1 << endl;
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

    string expression1_cpy = input_expression1;
    string expression2_cpy = input_expression2;
    while (!satisfiable)
    {
        // Try to edit expression 1.
        for (int i = 0; i < expression1_cpy.size(); i++)
        {
            vector<bool> result1;
            vector<bool> result2;

            vector<vector<bool>> inputs_matrix1;
            vector<vector<bool>> inputs_matrix2;

            vector<Expression *> inputs1;
            vector<Expression *> inputs2;
            if (expression1_cpy[i] == '&')
            {
                expression1_cpy[i] = '|';
                cout << "Trying expression 1 = " << expression1_cpy << endl;
                get_truth_table(expression1_cpy, result1, inputs_matrix1, inputs1);
                get_truth_table(expression2_cpy, result2, inputs_matrix2, inputs2);

                if (is_satisfiable(result1, result2, inputs_matrix1, inputs1))
                {
                    cout << "The expressions become satisfiable if you change expression 1 to " << expression1_cpy;
                    return 0;
                }
            }
            expression1_cpy = input_expression1;
        }

        // Then try to edit expression 2.
        for (int i = 0; i < expression2_cpy.size(); i++)
        {
            vector<bool> result1;
            vector<bool> result2;

            vector<vector<bool>> inputs_matrix1;
            vector<vector<bool>> inputs_matrix2;

            vector<Expression *> inputs1;
            vector<Expression *> inputs2;
            if (expression2_cpy[i] == '&')
            {
                expression2_cpy[i] = '|';
                cout << "Trying expression2 =" << expression2_cpy << endl;
                get_truth_table(expression1_cpy, result1, inputs_matrix1, inputs1);
                get_truth_table(expression2_cpy, result2, inputs_matrix2, inputs2);

                if (is_satisfiable(result1, result2, inputs_matrix1, inputs1))
                {
                    cout << "The expressions become satisfiable if you change expression 2 to " << expression2_cpy << endl;
                    return 0;
                }
            }
            expression2_cpy = input_expression2;
        }
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