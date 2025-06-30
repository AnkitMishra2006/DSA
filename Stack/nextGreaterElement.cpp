#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: Given an array of integers, find the next greater element for each element in the array.
// The next greater element for an element x is the first greater element on the right side of x in the array.
// If no such element exists, the next greater element is -1.
// Example: For the array [4, 5, 2, 10, 8], the next greater elements are [5, 10, 10, -1, -1].

int main()
{

    vector<int> arr = {6, 8, 0, 1, 3};
    stack<int> s;
    vector<int> ans(arr.size(), -1); // Initialize answer vector with -1

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        // Pop elements from the stack until we find a greater element
        while (s.size() > 0 && s.top() <= arr[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top(); // The top of the stack is the next greater element
        }

        s.push(arr[i]); // Push the current element onto the stack
    }

    // print the result
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
