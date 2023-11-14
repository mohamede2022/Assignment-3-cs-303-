
#include "func.h"

// checking if the character is an operand
bool isOperand(char ch) {
		return (ch >= '0' && ch <= '9');
}

// checking if the character is an operator
bool isOperator(char ch) {
		return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}

// checks the order of operations to see which one goes first
int precedence(char op) {
		if (op == '+' || op == '-')
				return 1;
		else if (op == '*' || op == '/' || op == '%')
				return 2;
		else
				return 0;
}

// converts infix expression to postfix expression
string infixToPostfix(string exp) {
	stack<char> st;
	string postfixExp = "";
	for (int i = 0; i < exp.length(); i++) {
			char ch = exp[i];
			if (isalpha(ch)) {
					postfixExp += ch;
			} else if (isOperator(ch)) {
					while (!st.empty() && st.top() != '(' && precedence(ch) <= precedence(st.top())) {
							postfixExp += st.top();
							st.pop();
					}
					st.push(ch);
			} else if (ch == '(') {
					st.push(ch);
			} else if (ch == ')') {
					while (!st.empty() && st.top() != '(') {
							postfixExp += st.top();
							st.pop();
					}
					if (!st.empty() && st.top() == '(') {
							st.pop();
					} else {
							return "Invalid Expression";
					}
			}
	}
	while (!st.empty()) {
			if (st.top() == '(' || st.top() == ')') {
					return "Invalid Expression";
			}
			postfixExp += st.top();
			st.pop();
	}
	return postfixExp;
}



// checks to see if the expression is balanced as in parenthesis balanced by checking opening and closing parenthesis
bool isBalanced(string exp) {
		stack<char> st;
		for (int i = 0; i < exp.length(); i++) {
				char ch = exp[i];
				if (ch == '{' || ch == '[' || ch == '(') {
						st.push(ch);
				} else if (ch == '}' || ch == ']' || ch == ')') {
						if (st.empty()) {
								return false;
						}
						if ((ch == '}' && st.top() == '{') || (ch == ']' && st.top() == '[') || (ch == ')' && st.top() == '(')) {
								st.pop();
						} else {
								return false;
						}
				}
		}
		return st.empty();
}