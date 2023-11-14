// Mohamed Elgasim
// Assignment-3 (CS-303)
// 11.13.2023
#include "func.h"

// asking the user for the infix expression and converting it to postfix expression
int main() {
		string infixExp;
		CustomQueue myQueue;
		cout << "Enter infix expression: ";
		getline(cin, infixExp);
		if (!isBalanced(infixExp)) {
				cout << "Unvalid expression due inbalanced expression" << endl;
		} else {
				string postfixExp = infixToPostfix(infixExp);
				cout << "Postfix expression: " << postfixExp << endl;
		}
	
		cout << "\n\n" << endl;

		// Inserting elements into the queue
		myQueue.enqueue(50);

		// Displaying the front element
		cout << "Front element: " << myQueue.front() << endl;

		// Dequeue an element
		cout << "Dequeued element: " << myQueue.dequeue() << endl;

		// Checking if the queue is empty
		cout << "Is queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;

		// Displaying the number of elements in the queue
		cout << "Number of elements in the queue: " << myQueue.size() << endl;
	return 0;
		
	
}