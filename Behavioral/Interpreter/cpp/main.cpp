#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Token {
    enum Type {
        integer, plus, minus, lparen, rparen
    } type;
    string text;

    Token(Type type, const string &text) : type(type), text(text) {}

    friend ostream &operator<<(ostream &os, const Token &t) {
        os << " `" << t.text << "` ";
        return os;
    }
};

vector<Token> lex(const string &input) {
    vector<Token> result;

    for (int i = 0; i < input.size(); i++) {
        switch (input[i]) {
            case '+':
                result.push_back(Token{Token::plus, "+"});
                break;
            case '-':
                result.push_back(Token{Token::minus, "-"});
                break;
            case '(':
                result.push_back(Token{Token::lparen, "("});
                break;
            case ')':
                result.push_back(Token{Token::rparen, ")"});
                break;
            default:
                ostringstream buffer;
                buffer << input[i];
                for (int j = i + 1; j < input.size(); j++) {
                    if (isdigit(input[j])) {
                        buffer << input[j];
                        i++;
                    } else {
                        result.push_back(Token{Token::integer, buffer.str()});
                        break;
                    }
                }
        }
    }
    return result;
}

struct Element {
    virtual int eval() const = 0;
};

struct Integer : Element {
    int value;

    Integer(int v) : value(v) {}

    int eval() const override {
        return value;
    }
};

struct BinaryOperation : Element {
    enum Type {
        addition, subtraction
    } type;
    shared_ptr<Element> lhs, rhs;

    int eval() const override {
        auto left = lhs->eval();
        auto right = lhs->eval();
        if (type == addition) {
            return left + right;
        } else {
            return left - right;
        }
    }
};

shared_ptr<Element> parse(const vector<Token> &tokens) {
    auto result = make_unique<BinaryOperation>();
    bool have_lfs{false};

    for (int i = 0; i < tokens.size(); ++i) {
        auto &token = tokens[i];
        switch (token.type) {
            case Token::integer: {
                            int value = stoi(token.text);
                            auto integer = make_shared<Integer>(value);
                            if (!have_lfs) {
                                result->lhs = integer;
                                have_lfs = true;
                            } else {
                                result->rhs = integer;
                            }
                        }
                        break;
            case Token::minus:
                        result->type = BinaryOperation::subtraction;
                        break;
            case Token::plus:
                result->type = BinaryOperation::addition;
                break;
            case Token::lparen: {
                int j = i; // cache current index
                for (; j < tokens.size(); j++) {
                    if (tokens[i].type == Token::rparen)
                        break;
                }
                vector<Token> subexpression(&tokens[i + 1], &tokens[j]);
                auto element = parse(subexpression);
                if (!have_lfs) {
                    result->lhs = element;
                    have_lfs = true;
                } else {
                    result->rhs = element;
                }
                i = j;
            }
                break;
            case Token::rparen:
                break;
        }
    }
}

int main() {
    string input{"(30+2)-(14-3)"};
    auto tokens = lex(input);
    for (auto &t: tokens) {
        cout << t << " ";
    }

    try {
        auto parsed = parse(tokens);
        cout << input << " = " << parsed->eval() << endl;
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
