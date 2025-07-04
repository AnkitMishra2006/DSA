#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int capacity;
    int currSize;
    int f, r;

public:
    Queue(int size)
    {
        capacity = size;
        arr = new int[size];
        currSize = 0;
        f = -1;
        r = -1;
    }

    void push(int x)
    {
        if (currSize == capacity)
        {
            cout << "Queue overflow." << endl;
            return;
        }

        if (f == -1)
        {
            f = 0;
        }

        r = (r + 1) % capacity;
        arr[r] = x;
        currSize++;
    }

    int pop()
    {
        if (currSize == 0)
        {
            cout << "Queue underflow." << endl;
            return -1; // Indicating an error
        }

        int poppedValue = arr[f];
        f = (f + 1) % capacity;
        currSize--;

        if (currSize == 0)
        {
            f = -1;
            r = -1;
        }

        return poppedValue;
    }

    int front()
    {
        if (currSize == 0)
        {
            cout << "Queue is empty." << endl;
            return -1; // Indicating an error
        }
        return arr[f];
    }

    bool empty()
    {
        return currSize == 0;
    }
};

int main()
{

    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6); // This should show "Queue overflow."
    cout << "Front element: " << q.front() << endl;
    cout << "Popped element: " << q.pop() << endl;
    cout << "Front element after pop: " << q.front() << endl;
    cout << "Popped element: " << q.pop() << endl;
    cout << "Popped element: " << q.pop() << endl;
    cout << "Popped element: " << q.pop() << endl;
    cout << "Popped element: " << q.pop() << endl;
    cout << "Popped element from empty queue: " << q.pop() << endl;
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;
    q.push(7);
    cout << "Front element after pushing 7: " << q.front() << endl;
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;
    cout << "Popped element: " << q.pop() << endl;
    cout << "Popped element: " << q.pop() << endl;
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}