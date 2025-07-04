#include <iostream>
#include <deque>
using namespace std;

// Stack class using deque
class Stack
{
private:
    deque<int> dq;

public:
    // Push operation
    void push(int value)
    {
        dq.push_back(value);
    }
    // Pop operation
    void pop()
    {
        if (dq.empty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        dq.pop_back();
    }
    // Get the top element
    int top()
    {
        if (dq.empty())
        {
            cout << "Stack is empty!" << endl;
            return -1; // Indicating empty stack
        }
        return dq.back();
    }
    // Check if the stack is empty
    bool isEmpty()
    {
        return dq.empty();
    }
    // Get the size of the stack
    int size()
    {
        return dq.size();
    }
    // Display the stack elements
    void display()
    {
        if (dq.empty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int value : dq)
        {
            cout << value << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack stack;

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Display the stack
    stack.display();

    // Get the top element
    cout << "Top element: " << stack.top() << endl;

    // Pop an element from the stack
    stack.pop();
    cout << "After popping, ";
    stack.display();

    // Check if the stack is empty
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}