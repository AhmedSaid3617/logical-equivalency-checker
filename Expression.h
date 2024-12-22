#include <string>
#include <vector>

class Expression
{
protected:
    Expression* child;

public:
    Expression(/* args */);
    Expression(std::string &expression_str, std::vector<Expression*> &inputs);
    virtual bool evaluate();
    ~Expression();
};

/********************************* */

class TwoInputExpression : public Expression
{
protected:
    Expression* left;
    Expression* right;
    TwoInputExpression(std::string &expression_str, std::vector<Expression*> &inputs);

public:
    TwoInputExpression(/* args */);
    ~TwoInputExpression();
};

/********************************* */
class And: public TwoInputExpression
{
private:

public:
    And(/* args */);
    And(Expression* left, Expression* right);
    And(std::string &expression_str, std::vector<Expression*> &inputs);
    bool evaluate() override;
    ~And();
};

/********************************* */

class Or: public TwoInputExpression
{
private:

public:
    Or(/* args */);
    Or(Expression* left, Expression* right);
    Or(std::string &expression_str, std::vector<Expression*> &inputs);
    bool evaluate() override;
    ~Or();
};

/********************************* */

class Not: public Expression
{
private:
    /* data */
public:
    Not(/* args */);
    Not(Expression* input);
    Not(std::string &expression_str, std::vector<Expression*> &inputs);
    bool evaluate() override;
    ~Not();
};

/********************************* */
class Input : public Expression
{
private:
    bool _input;
    char name;
public:
    Input();
    Input(char name);
    void set_input(bool input);
    char get_name();
    bool evaluate() override ;
    ~Input();
};




