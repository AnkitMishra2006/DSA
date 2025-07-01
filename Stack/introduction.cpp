#include <iostream>
#include <vector>
using namespace std;

template <class T>
class stack
{
    vector<T> v;
    int top;

public:
    stack()
    {
        top = -1;
    }

    void push(int x)
    {
        v.push_back(x);
        top++;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        v.pop_back();
        top--;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return v[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

};

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << st.peek() << endl;
    st.pop();

    cout << st.peek() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    cout << st.peek() << endl;

    return 0;
}