#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int> &org)
{
    int n = org.size();
    queue<int> temp;
    for (int i = 0; i < n / 2; i++)
    {
        temp.push(org.front());
        org.pop();
    }
    while (!temp.empty())
    {
        org.push(temp.front());
        temp.pop();
        if (!org.empty())
        {
            org.push(org.front());
            org.pop();
        }
    }
}

int main()
{
    queue<int> org;
    for (int i = 1; i <= 10; i++)
    {
        org.push(i);
    }

    interleave(org);

    for (int i = 0; i < 10; i++)
    {
        cout << org.front() << " ";
        org.pop();
    }
    cout << endl;

    return 0;
}