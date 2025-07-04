#include <iostream>
#include <deque>
using namespace std;

class Queue
{
private:
    deque<int> dq;

public:
    // Enqueue operation
    void enqueue(int value)
    {
        dq.push_back(value);
    }
    // Dequeue operation
    void dequeue()
    {
        if (dq.empty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        dq.pop_front();
    }
    // Get the front element
    int front()
    {
        if (dq.empty())
        {
            cout << "Queue is empty!" << endl;
            return -1; // Indicating empty queue
        }
        return dq.front();
    }
    // Check if the queue is empty
    bool isEmpty()
    {
        return dq.empty();
    }
    // Get the size of the queue
    int size()
    {
        return dq.size();
    }
    // Display the queue elements
    void display()
    {
        if (dq.empty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int value : dq)
        {
            cout << value << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "Front element: " << q.front() << endl;
    q.dequeue();
    q.display();

    cout << "Queue size: " << q.size() << endl;
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue(); // Attempt to dequeue from an empty queue
    q.display();
    cout << "Queue size after dequeuing all elements: " << q.size() << endl;
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}