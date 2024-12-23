#include <string>
#include <vector>

class Expression
{
private:
    
protected:
    Expression* child;
    char symbol;
    virtual char get_symbol();

public:
    Expression(/* args */);
    Expression(std::string &expression_str, std::vector<Expression*> &inputs);
    virtual bool evaluate();
    virtual void print();
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
    void print() override;
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
    char get_symbol() override;
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
    char get_symbol() override;
    ~Or();
};

/********************************* */

class Not: public Expression
{
private:

public:
    Not(/* args */);
    Not(Expression* input);
    Not(std::string &expression_str, std::vector<Expression*> &inputs);
    bool evaluate() override;
    char get_symbol() override;
    ~Not();
};

/********************************* */
class Input : public Expression
{
private:
    bool _input;
public:
    Input();
    Input(char name);
    void set_input(bool input);
    char get_symbol();
    bool evaluate() override ;
    static bool compare(Expression* in1, Expression* in2);
    ~Input();
};




