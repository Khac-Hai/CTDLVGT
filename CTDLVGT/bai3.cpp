#include <iostream>
#include <string>
#include <stack>
#include <cctype>

int getPriority(char op) {
    if (op == '/' || op == '*')
        return 1;
    else if (op == '+' || op == '-')
        return 0;
    return -1; 
}

std::string InfixToPostfix(const std::string &expression) {
    std::stack<char> st;
    std::string postfix = "";

    for (char c : expression) {
        if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); 
        } else if (std::isdigit(c) || std::isalpha(c)) {
            postfix += c;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!st.empty() && st.top() != '(' && getPriority(st.top()) >= getPriority(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int CalculateExpression(const std::string &expression) {
    std::stack<int> st;

    for (char c : expression) {
        if (std::isdigit(c)) {
            st.push(c - '0'); 
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();

            switch (c) {
                case '+':
                    st.push(x + y);
                    break;
                case '-':
                    st.push(x - y);
                    break;
                case '*':
                    st.push(x * y);
                    break;
                case '/':
                    st.push(x / y);
                    break;
            }
        }
    }

    return st.top();
}

int main() {
    std::string bieuthu_infix;
    std::cout << "nhap bieu thuc trung to: ";
    std::getline(std::cin, bieuthu_infix);

    std::string bieuthuc_postfix = InfixToPostfix(bieuthu_infix);
    std::cout << "bieu thuc Postfix : " << bieuthuc_postfix << std::endl;

    int result = CalculateExpression(bieuthuc_postfix);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
