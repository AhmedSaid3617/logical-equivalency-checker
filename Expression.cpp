#include "Expression.h"

Expression::Expression(/* args */)
{
}

Expression::Expression(Expression *left, Expression *right)
{
    this->left = left;
    this->right = right;
}

bool Expression::evaluate()
{
    return false;
}

Expression::~Expression()
{
}

/************************************* */
And::And(/* args */)
{
}

And::And(Expression *left, Expression *right):Expression(left, right)
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

void Input::set_input(bool input)
{
    this->_input = input;
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

Or::Or(Expression *left, Expression *right) : Expression(left, right)
{

}

bool Or::evaluate()
{
    return this->left->evaluate() || this->right->evaluate();
}

Or::~Or()
{
}
