#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <sstream>
#include <map>
#include <stdexcept>

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
    return !token.empty() && all_of(token.begin(), token.end(), ::isdigit);
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

int evaluatePostfix(const vector<string>& postfix) {
    StackinArray evaluationStack;

    for (const auto& token : postfix) {
        if (isNumber(token)) {
            evaluationStack.push(token);
        } else if (isOperator(token)) {
            if (token == "min" || token == "max") {
                int b = stoi(evaluationStack.pop());
                int a = stoi(evaluationStack.pop());
                if (token == "min") {
                    evaluationStack.push(to_string(min(a, b)));
                } else {
                    evaluationStack.push(to_string(max(a, b)));
                }
            } else {
                int b = stoi(evaluationStack.pop());
                int a = stoi(evaluationStack.pop());
                if (token == "+") {
                    evaluationStack.push(to_string(a + b));
                } else if (token == "-") {
                    evaluationStack.push(to_string(a - b));
                } else if (token == "*") {
                    evaluationStack.push(to_string(a * b));
                } else if (token == "/") {
                    evaluationStack.push(to_string(a / b));
                }
            }
        }
    }

    return stoi(evaluationStack.pop());
}

int main() {
    string expression;
    getline(cin, expression);

        vector<string> postfix = shuntingYard(expression);
        int result = evaluatePostfix(postfix);
        cout << result << endl;
    
    return 0;
}