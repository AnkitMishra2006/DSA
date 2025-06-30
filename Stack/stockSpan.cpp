#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// Problem Statement: Given an array of stock prices, find the span of stock prices for each day.
//  The span of the stock price on a given day is defined as the maximum number of consecutive days
//  before the given day for which the stock price was less than or equal to the stock price on that day.
//  The span for the first day is always 1.
//  Example: For the stock prices [100, 80, 60, 70, 60, 75, 85], the spans are [1, 1, 1, 2, 1, 4, 6].

int main()
{
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    vector<int> ans(price.size(), 0); // Initialize answer vector with size of price vector
    stack<int> s;   

    for (int i = 0; i < price.size(); i++)
    {
        while (s.size() > 0 && price[s.top()] <= price[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = i + 1; // If stack is empty, span is i + 1
        }
        else
        {
            ans[i] = i - s.top(); // Span is current index - index of last higher price
        }

        s.push(i); // Push current index onto the stack
    }

    for (int i : ans)
    {
        cout << i << " ";
    }

    return 0;
}
