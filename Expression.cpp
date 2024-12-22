#include "Expression.h"

Expression::Expression(/* args */)
{
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

And::And(Expression *left, Expression *right)
{
    this->left = left;
    this->right = right;
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

Input::Input(std::string name)
{
    this->name = name;
}

void Input::set_input(bool input)
{
    this->_input = input;
}

std::string Input::get_name()
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

bool Not::evaluate()
{
    return !child->evaluate();
}

Not::~Not()
{
}
