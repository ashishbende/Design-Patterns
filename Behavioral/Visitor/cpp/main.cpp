#include <iostream>
#include <sstream>

using namespace std;

// forward declare
struct DoubleExpression;
struct AdditionExpression;
struct SubtractionExpression;

// an interface that needs to be implemented by visitor
struct ExpressionVisitor{
    virtual void visit(DoubleExpression *de)=0;
    virtual void visit(AdditionExpression *ae)=0;
    virtual void visit(SubtractionExpression *se)=0;
};

// expression interface
struct Expression{
    virtual ~Expression() = default;
    virtual void print(ostringstream &oss)=0;
    virtual void accept(ExpressionVisitor *visitor)=0;
};
struct DoubleExpression : Expression{
    double value;
    DoubleExpression(double value) : value(value){}

    void print(ostringstream &oss) override {
        oss << value;
    }

    void accept(ExpressionVisitor *visitor) override {
        visitor->visit(this);
    }
};
struct AdditionExpression: Expression{
    Expression *left, *right;

    AdditionExpression(Expression *left, Expression *right) : left(left), right(right) {}

    virtual ~AdditionExpression() {
        delete left;
        delete right;
    }

    void print(ostringstream &oss) override {
        oss << "(";
        left->print(oss);
        oss << "+";
        right->print(oss);
        oss <<")";
    }

    void accept(ExpressionVisitor *visitor) override {
        visitor->visit(this);
    }
};
struct SubtractionExpression: Expression{
    Expression *left, *right;

    SubtractionExpression(Expression *left, Expression *right) : left(left), right(right) {}

    virtual ~SubtractionExpression() {
        delete left;
        delete right;
    }

    void print(ostringstream &oss) override {
        oss << "(";
        left->print(oss);
        oss << "-";
        right->print(oss);
        oss <<")";
    }

    void accept(ExpressionVisitor *visitor) override {
        visitor->visit(this);
    }
};

// the visitor
struct ExpressionPrinter : ExpressionVisitor{
    ostringstream oss;
    string str(){
        return oss.str();
    }
    void visit(DoubleExpression *de) override;
    void visit(AdditionExpression *ae) override;
    void visit(SubtractionExpression *se) override;
};

void ExpressionPrinter::visit(DoubleExpression *de){
    oss << de->value;
}
void ExpressionPrinter::visit(AdditionExpression *ae){
    // oss << "(";
    // ae->left->accept(this);
    // oss << "+";
    // ae->right->accept(this);
    // oss <<")";

    bool need_braces = dynamic_cast<SubtractionExpression*>(ae->right);
    ae->left->accept(this);
    oss <<"+";
    if(need_braces) oss <<  "(";
    ae->right->accept(this);
    if(need_braces) oss << ")";
}

void ExpressionPrinter::visit(SubtractionExpression *se){
    bool need_braces = dynamic_cast<SubtractionExpression*>(se->right);

    if(need_braces) oss <<  "(";
    se->left->accept(this);// double dispatch
    oss << "-";
    se->right->accept(this);
    if(need_braces) oss << ")";
}

// another visitor
struct ExpressionEvaluator : ExpressionVisitor{
    double result;
    void visit(DoubleExpression *de) override;
    void visit(AdditionExpression *ae) override;
    void visit(SubtractionExpression *se) override;
};

void ExpressionEvaluator::visit(DoubleExpression *de) {
    result = de->value;
}

void ExpressionEvaluator::visit(AdditionExpression *ae) {
    ae->left->accept(this);
    auto temp = result;
    ae->right->accept(this);
    result += temp;
}

void ExpressionEvaluator::visit(SubtractionExpression *se) {
    se->left->accept(this);
    auto temp = result;
    se->right->accept(this);
    result = temp - result;
}

int main() {
    auto e = new AdditionExpression{
      new DoubleExpression{1}, new AdditionExpression{
          new DoubleExpression{2}, new DoubleExpression{3}}
    };

    ExpressionPrinter ep;
    ep.visit(e);
    cout << ep.str()<<endl;

    auto e1 = new AdditionExpression{
        new DoubleExpression{1}, new SubtractionExpression{
            new DoubleExpression{2}, new DoubleExpression{3}
        }
    };

    ExpressionPrinter ep2;
    ep2.visit(e1);
    cout << ep2.str() << endl;

    ExpressionEvaluator ev;
    ev.visit(e1);
    cout << ep2.str() <<" = " << ev.result << endl;

    delete e;
    delete e1;


    return 0;
}
