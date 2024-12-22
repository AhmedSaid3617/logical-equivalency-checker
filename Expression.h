class Expression
{
protected:
    Expression* left;
    Expression* right;
public:
    Expression(/* args */);
    Expression(Expression* left, Expression* right);
    virtual bool evaluate();
    ~Expression();
};

/********************************* */
class And: public Expression
{
private:
    /* data */
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
    /* data */
public:
    Or(/* args */);
    Or(Expression* left, Expression* right);
    bool evaluate() override;
    ~Or();
};


/********************************* */
class Input : public Expression
{
private:
    bool _input;
public:
    Input(/* args */);
    void set_input(bool input);
    bool evaluate() override ;
    ~Input();
};




