#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

// Convert a character to its numeric value (for single digits)
float scanNum(char ch){
    return float(ch - '0');
}

// Check if the character is an operator
int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    return -1;
}

// Check if the character is an operand (number)
int isOperand(char ch){
    if(ch >= '0' && ch <= '9')
        return 1;
    return -1;
}

// Perform the operation on two operands
float operation(float a, float b, char op){
    if(op == '+')
        return a + b;
    else if(op == '-')
        return a - b;
    else if(op == '*')
        return a * b;
    else if(op == '/')
        return a / b;
    else if(op == '^')
        return pow(a, b);
    
    return 0;  // Return 0 in case of an unknown operator
}

// Function to evaluate the postfix expression
float postfixEval(string postfix){
    int l = postfix.length();
    stack<float> stk;

    for(int i = 0; i < l; i++){
        // If the character is an operator, pop two operands and apply the operation
        if(isOperator(postfix[i]) != -1){
            float b = stk.top(); stk.pop();
            float a = stk.top(); stk.pop();
            stk.push(operation(a, b, postfix[i]));
        }
        // If the character is an operand, push it onto the stack
        else if(isOperand(postfix[i]) > 0){
            stk.push(scanNum(postfix[i]));
        }
    }

    // The final result will be the top element of the stack
    return stk.top();
}

int main(){
    cout << "\nEnter the postfix expression for evaluation: ";
    string post;
    cin >> post;

    cout << "The result is: " << postfixEval(post) << endl;

    return 0;
}
