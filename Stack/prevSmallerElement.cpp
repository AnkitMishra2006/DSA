#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: Given an array of integers, find the previous smaller element for each element in the array.
// The previous smaller element for an element x is the first smaller element on the left side of
// x in the array. If no such element exists, the previous smaller element is -1.
// Example: For the array [3, 1, 0, 8, 6], the previous smaller elements are [-1, -1, -1, 0, 0].

int main()
{

    vector<int> arr = {3, 1, 0, 8, 6};
    stack<int> s;
    vector<int> ans(arr.size(), -1); // Initialize answer vector with -1

    for (int i = 0; i < arr.size(); i++)
    {
        // Pop elements from the stack until we find a greater element
        while (s.size() > 0 && s.top() >= arr[i])
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
