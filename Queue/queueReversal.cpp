#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    queue<int> q;
    for (int i = 1; i <= 10; i++)
    {
        q.push(i);
    }

    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < 10; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}