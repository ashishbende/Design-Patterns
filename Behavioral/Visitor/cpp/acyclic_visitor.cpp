#include <iostream>
#include <sstream>

using namespace  std;

template<typename Visitable>
struct Visitor{
    virtual  void visit(Visitable &obj)  = 0;
};

// marker struct
struct VisitorBase{
    virtual ~VisitorBase() = default;
};

struct Expression{
    virtual ~Expression() = default;
    virtual void accept(VisitorBase &obj){
        // try to make sure passed object is Visitor<T> type
        using EV = Visitor<Expression>;
        if(auto ev = dynamic_cast<EV*>(&obj)){
            ev->visit(*this);
        }
    }
};


struct DoubleExpression : Expression{
    double value;

    DoubleExpression(double value) : value(value) {}

    virtual void accept(VisitorBase &obj){
        // try to make sure passed object is Visitor<T> type
        using DEV = Visitor<DoubleExpression>;
        if(auto ev = dynamic_cast<DEV*>(&obj)){
            ev->visit(*this);
        }
    }
};

struct AdditionExpression : Expression{
    Expression *left;
    Expression *right;

    AdditionExpression(Expression *left, Expression *right) : left(left), right(right) {}

    virtual void accept(VisitorBase &obj){
        // try to make sure passed object is Visitor<T> type
        using AEV = Visitor<AdditionExpression>;
        if(auto ev = dynamic_cast<AEV*>(&obj)){
            ev->visit(*this);
        }
    }

    virtual ~AdditionExpression() {
        delete left;
        delete right;
    }
};


// visitor

struct ExpressionPrinter : VisitorBase,
                            Visitor<AdditionExpression>,
                            Visitor<DoubleExpression>{
    void visit(AdditionExpression &obj) override {
        oss << "(";
        obj.left->accept(*this);
        oss << "+";
        obj.right->accept(*this);
        oss <<")";
    }

    void visit(DoubleExpression &obj) override {
        oss << obj.value;
    }

    string str() const{
        return oss.str();
    }
private:
    ostringstream oss;

};

int main(){
    auto e = new AdditionExpression{
        new DoubleExpression{1}, new AdditionExpression{
            new DoubleExpression{2}, new DoubleExpression{3}
        }
    };

    ExpressionPrinter ep;
    ep.visit(*e);
    cout << ep.str() << endl;
    return 0;

}