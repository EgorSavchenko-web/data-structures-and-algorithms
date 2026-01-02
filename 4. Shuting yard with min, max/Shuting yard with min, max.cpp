#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <sstream>
#include <map>

using namespace std;

class myStack {
public:
    virtual void push(const string& value) = 0;
    virtual string pop() = 0;
    virtual string peek() const = 0;
    virtual bool isEmpty() const = 0;
    virtual ~myStack() {}
};

class StackinArray : public myStack {
private:
    vector<string> myvector;
public:
    void push(const string& value) override {
        myvector.push_back(value);
    }

    string pop() override {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        string value = myvector.back();
        myvector.pop_back();
        return value;
    }

    string peek() const override {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return myvector.back();
    }

    bool isEmpty() const override {
        return myvector.empty();
    }
};

int precedence(const string& token) {
    if (token == "+" || token == "-") return 1;
    if (token == "*" || token == "/") return 2;
    if (token == "min" || token == "max") return 3;
    return 0;
}

bool isOperator(const string& token) {
    return (token == "+" || token == "-" || token == "*" || token == "/" || token == "min" || token == "max");
}

bool isNumber(const string& token) {
    return (!(token == "+" || token == "-" || token == "*" || token == "/" || token == "min" || token == "max" || token == ","));
}

vector<string> shuntingYard(const string& expression) {
    StackinArray operatorStack;
    vector<string> output;
    istringstream iss(expression);
    string token;

    while (iss >> token) {
        if (isNumber(token)) {
            output.push_back(token);
        } else if (token == "(") {
            operatorStack.push(token);
        } else if (token == ",") {
            while (!operatorStack.isEmpty() && operatorStack.peek() != "(") {
                output.push_back(operatorStack.pop());
            }
        } else if (token == ")") {
            while (!operatorStack.isEmpty() && operatorStack.peek() != "(") {
                output.push_back(operatorStack.pop());
            }
            if (!operatorStack.isEmpty() && operatorStack.peek() == "(") {
                operatorStack.pop(); // Remove "("
            }
            if (!operatorStack.isEmpty() && (operatorStack.peek() == "min" || operatorStack.peek() == "max")) {
                output.push_back(operatorStack.pop());
            }
        } else if (isOperator(token)) {
            while (!operatorStack.isEmpty() && precedence(operatorStack.peek()) >= precedence(token)) {
                output.push_back(operatorStack.pop());
            }
            operatorStack.push(token);
        }
    }

    while (!operatorStack.isEmpty()) {
        output.push_back(operatorStack.pop());
    }

    return output;
}

int main() {
    string expression;
    getline(cin, expression);

    try {
        vector<string> postfix = shuntingYard(expression);

        for (const auto& token : postfix) {
            cout << token << " ";
        }
        cout << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}