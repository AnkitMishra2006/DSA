#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Problem: Find the celebrity in a party
//  A celebrity is a person who is known by everyone but knows no one.
//  Approach: Use a stack to keep track of potential celebrities.

int getCelebrity(vector<vector<int>> arr)
{
    int n = arr.size();
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (arr[a][b] == 1)
        {
            // a knows b, so a cannot be a celebrity
            s.push(b);
        }
        else
        {
            // a does not know b, so b cannot be a celebrity
            s.push(a);
        }
    }

    int celeb = s.top();
    for (int i = 0; i < n; i++)
    {
        if (i != celeb)
        {
            // Check if celeb knows anyone or is known by anyone
            if (arr[celeb][i] == 1 || arr[i][celeb] == 0)
            {
                return -1; // No celebrity found
            }
        }
    }

    return celeb; // Celebrity found
}

int main()
{

    vector<vector<int>> arr = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 1, 0}};

    int ans = getCelebrity(arr);
    if (ans == -1)
    {
        cout << "No celebrity found" << endl;
    }
    else
    {
        cout << "Celebrity is person " << ans << endl;
    }

    return 0;
}