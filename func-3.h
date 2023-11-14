#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;

// Creating the customqueue class
class CustomQueue {
private:
		std::queue<int> q;

public:
		// Inserts a new element at the rear of the queue
		void enqueue(int element) {
				q.push(element);
		}

		// Removes the front element of the queue and returns it
		int dequeue() {
				if (isEmpty()) {
						std::cout << "Queue is empty. Cannot dequeue." << std::endl;
						return -1; // Return a default value or handle the error accordingly
				}
				int frontElement = q.front();
				q.pop();
				return frontElement;
		}

		// Returns the front element present in the queue without removing it
		int front() {
				if (isEmpty()) {
						std::cout << "Queue is empty." << std::endl;
						return -1; // Return a default value or handle the error accordingly
				}
				return q.front();
		}

		// Checks if the queue is empty
		bool isEmpty() {
				return q.empty();
		}

		// Returns the total number of elements present in the queue
		int size() {
				return q.size();
		}
};

bool isOperand(char ch);
bool isOperator(char ch);
string infixToPostfix(string exp);
bool isBalanced(string exp);