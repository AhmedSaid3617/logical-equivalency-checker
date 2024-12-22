#include "Expression.h"
#include "Postfix.h"

Expression::Expression(/* args */)
{
}

Expression::Expression(std::string &expression_str, std::vector<Expression *> &inputs)
{

    if (!isOperator(expression_str[0]))
    {
        // See if the input has already been recorded.
        for (Expression *input : inputs)
        {
            if (((Input*)input)->get_name() == expression_str[0])
            {
                // Add it to the input list to be used in truth table generation.
                this->child = input;
                return;
            }
        }

        // If it's new then create an input and add it to the list.
        Input *new_input = new Input(expression_str[0]);
        this->child = new_input;
        inputs.push_back(new_input);
        expression_str.erase(expression_str.begin());
        return;
    }
    else
    {
        switch (expression_str[0])
        {
        case '&':
            // Remove the processed part of the string.
            expression_str.erase(expression_str.begin());
            this->child = new And(expression_str, inputs);
            break;

        case '|':
            // Remove the processed part of the string.
            expression_str.erase(expression_str.begin());
            this->child = new Or(expression_str, inputs);
            break;

        case '~':
            // Remove the processed part of the string.
            expression_str.erase(expression_str.begin());
            this->child = new Not(expression_str, inputs);
            break;

        default:
            break;
        }
    }
}

bool Expression::evaluate()
{
    return this->child->evaluate();
}

Expression::~Expression()
{
}

/************************************* */

TwoInputExpression::TwoInputExpression(){

}

TwoInputExpression::TwoInputExpression(std::string &expression_str, std::vector<Expression *> &inputs)
{
    // For the left child.
    if (!isOperator(expression_str[0]))
    {
        // See if the input has already been recorded.
        for (Expression *input : inputs)
        {
            if (((Input*)input)->get_name() == expression_str[0])
            {
                // Add it to the input list to be used in truth table generation.
                this->left = input;
                return;
            }
        }

        // If it's new then create an input and add it to the list.
        Input *new_input = new Input(expression_str[0]);
        this->left = new_input;
        inputs.push_back(new_input);
        expression_str.erase(expression_str.begin());
    }
    else
    {
        switch (expression_str[0])
        {
        case '&':
            // Remove the processed part of the string.
            expression_str.erase(expression_str.begin());
            this->left = new And(expression_str, inputs);
            break;

        case '|':
            // Remove the processed part of the string.
            expression_str.erase(expression_str.begin());
            this->left = new Or(expression_str, inputs);
            break;

        case '~':
            // Remove the processed part of the string.
            expression_str.erase(expression_str.begin());
            this->left = new Not(expression_str, inputs);
            break;

        default:
            break;
        }
    }

    // For the right child.
    if (!isOperator(expression_str[0]))
    {
        // See if the input has already been recorded.
        for (Expression *input : inputs)
        {
            if (((Input*)input)->get_name() == expression_str[0])
            {
                // Add it to the input list to be used in truth table generation.
                this->right = input;
                return;
            }
        }

        // If it's new then create an input and add it to the list.
        Input *new_input = new Input(expression_str[0]);
        this->right = new_input;
        inputs.push_back(new_input);
        expression_str.erase(expression_str.begin());
    }
    else
    {
        switch (expression_str[0])
        {
        case '&':
            // Remove the processed part of the string.
            expression_str.erase(expression_str.begin());
            this->right = new And(expression_str, inputs);
            break;

        case '|':
            // Remove the processed part of the string.
            expression_str.erase(expression_str.begin());
            this->right = new Or(expression_str, inputs);
            break;

        case '~':
            // Remove the processed part of the string.
            expression_str.erase(expression_str.begin());
            this->right = new Not(expression_str, inputs);
            break;

        default:
            break;
        }
    }
}


TwoInputExpression::~TwoInputExpression(){

}



/************************************* */
And::And(/* args */)
{
}

And::And(Expression *left, Expression *right)
{
    this->left = left;
    this->right = right;
}

And::And(std::string &expression_str, std::vector<Expression *> &inputs) : TwoInputExpression(expression_str, inputs)
{
}

And::~And()
{
}

bool And::evaluate()
{
    return this->left->evaluate() && this->right->evaluate();
}

/************************************** */
Input::Input(/* args */)
{
}

Input::Input(char name)
{
    this->name = name;
}

void Input::set_input(bool input)
{
    this->_input = input;
}

char Input::get_name()
{
    return this->name;
}

bool Input::evaluate()
{
    return this->_input;
}

Input::~Input()
{
}

/*********************************** */

Or::Or()
{
}

Or::Or(Expression *left, Expression *right)
{
    this->left = left;
    this->right = right;
}

Or::Or(std::string &expression_str, std::vector<Expression *> &inputs) : TwoInputExpression(expression_str, inputs)
{
}

bool Or::evaluate()
{
    return this->left->evaluate() || this->right->evaluate();
}

Or::~Or()
{
}

/********************************* */

Not::Not()
{
}

Not::Not(Expression *input)
{
    this->child = input;
}

Not::Not(std::string &expression_str, std::vector<Expression *> &inputs) : Expression(expression_str, inputs)
{
    
}

bool Not::evaluate()
{
    return !child->evaluate();
}

Not::~Not()
{
}
