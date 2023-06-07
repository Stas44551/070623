#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node {
    int value;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }
    void push(int value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            throw logic_error("Cannot pop from empty stack");
        }

        Node* temp = top;
        int value = top->value;
        top = top->next;
        delete temp;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            throw logic_error("Cannot peek into empty stack");
        }

        return top->value;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;
    for (int i = 0; i < 100; i++) {
        int value = rand() % 301 - 150;
        stack.push(value);
    }

    Stack stack1;
    Stack stack2;

    while (!stack.isEmpty()) {
        int value = stack.pop();

        if (value > 50) {
            stack1.push(value);
        }
        else {
            stack2.push(value);
        }
    }

    cout << "Stack1: ";
    while (!stack1.isEmpty()) {
        cout << stack1.pop() << " ";
    }
    cout << endl;

    cout << "Stack2: ";
    while (!stack2.isEmpty()) {
        cout << stack2.pop() << " ";
    }
    cout << endl;

    return 0;
}