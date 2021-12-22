#include <bits/stdc++.h>
using namespace std;

int precedence (char ch) {
    
    if (ch == '^') 
        return 3;
    
    else if (ch == '*' || ch == '/') 
        return 2;
    
    else if (ch == '+' || ch == '-')
        return 1;

    else return -1;
}

string infixToPostfix (string str) {
    string res = "";
    stack <char> st;

    for (int i = 0; i < str.length(); i++){
        
        if (isalpha(str[i])) {  // if character then add to result
            res += str[i];
        }
        else if (str[i] == '(') { // if '(' then push to stack
            st.push(str[i]);
        }
        else if (str[i] == ')') { // if ')' then pop from stack and add to result until '('
            while (st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else { // if operator occurs, higher precedence operator should be added to result 
            while (!st.empty() && precedence(str[i]) <= precedence(st.top())) {
                res += st.top();
                st.pop();
            }
            st.push(str[i]); // after that the current operator should be pushed
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

int main(int argc, char const *argv[]) {
    string s = "(A-B)*(D/E)"; //"a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostfix(s) << endl;
    return 0;
}
