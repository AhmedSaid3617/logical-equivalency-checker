#include <string>

class Expression
{
protected:
    Expression* child;
public:
    Expression(/* args */);
    //Expression(Expression* left, Expression* right);
    virtual bool evaluate();
    ~Expression();
};

/********************************* */
class And: public Expression
{
private:
    Expression* left;
    Expression* right;
public:
    And(/* args */);
    And(Expression* left, Expression* right);
    bool evaluate() override;
    ~And();
};

/********************************* */

class Or: public Expression
{
private:
    Expression* left;
    Expression* right;
public:
    Or(/* args */);
    Or(Expression* left, Expression* right);
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
    bool evaluate() override;
    ~Not();
};

/********************************* */
class Input : public Expression
{
private:
    bool _input;
    std::string name;
public:
    Input();
    Input(std::string name);
    void set_input(bool input);
    std::string get_name();
    bool evaluate() override ;
    ~Input();
};




