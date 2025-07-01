#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }

    int topele = st.top();
    st.pop();
    insertAtBottom(st, ele);

    st.push(topele);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Stack before inserting at bottom: ";
    stack<int> temp = st; // Copy stack to print
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    insertAtBottom(st, 5);

    cout << "Stack after inserting 5 at bottom: ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}