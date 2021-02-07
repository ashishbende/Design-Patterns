#include <iostream>
#include <sstream>

using namespace std;

class DoubleExpression;

class AdditionExpression;

struct ExpressionVisitor{
    virtual void visit(DoubleExpression *de)=0;
    virtual void visit(AdditionExpression *de)=0;
};
struct Expression{
    virtual ~Expression() = default;
    virtual void print(ostringstream& oss)=0;
    virtual void accept(ExpressionVisitor* visitor)=0;
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

struct ExpressionPrinter : ExpressionVisitor{
    ostringstream oss;
    void print(Expression *e){
        if( auto de = dynamic_cast<DoubleExpression*>(e)){
            oss<<de->value;
        }else if(auto ad = dynamic_cast<AdditionExpression*>(e)){
            oss << "(";
            ad->left->print(oss);
            oss << "+";
            ad->right->print(oss);
            oss <<")";
        }
    }

    string str(){
        return oss.str();
    }

    void visit(DoubleExpression *de) override;
    void visit(AdditionExpression *de) override;
};

void ExpressionPrinter::visit(DoubleExpression *de){
    oss<<de->value;
}

void ExpressionPrinter::visit(AdditionExpression *ae){

    oss << "(";
    ae->left->accept(this);
    oss << "+";
    ae->right->accept(this);
    oss <<")";
}
int main() {
    auto e = new AdditionExpression{
      new DoubleExpression{1}, new AdditionExpression{
          new DoubleExpression{2}, new DoubleExpression{3}}
    };

//    ostringstream ss;
//    e->print(ss);
//    cout << ss.str()<<endl;

    ExpressionPrinter ep;
    ep.print(e);
    cout << ep.str()<<endl;

    delete e;
    return 0;
}
