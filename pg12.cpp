// infix expression to postfix expression
// Infix: a+b*c Postfix: abc*+
#include<iostream>
#include<stack>
using namespace std;

int prec(char c){
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s){
    stack<char> st;
    st.push('N');
    int l = s.length();
    string ns;

    for(int i = 0; i < l; i++){
        // If the character is an operand, add it to the output string.
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            ns += s[i];
        }
        // If the character is '(', push it onto the stack.
        else if (s[i] == '('){
            st.push('(');
        }
        // If the character is ')', pop and add to the output string until '(' is found.
        else if(s[i] == ')'){
            while(st.top() != 'N' && st.top() != '('){
                char c = st.top();
                st.pop();
                ns += c;
            }
            if(st.top() == '('){
                st.pop(); // Pop the '(' from the stack
            }
        }
        // If an operator is encountered
        else{
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top())){
                char c = st.top();
                st.pop();
                ns += c;
            }
            st.push(s[i]); // Push current operator onto the stack
        }
    }

    // Pop all the remaining operators from the stack
    while(st.top() != 'N'){
        char c = st.top();
        st.pop();
        ns += c;
    }

    // Print the postfix expression
    cout << ns << endl;
}

int main(){
    cout << "Enter the arithmetic expression: ";
    string exp;
    cin >> exp;
    infixToPostfix(exp);
    return 0;
}
