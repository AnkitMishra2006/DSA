#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the maximum value of items that can be put in a knapsack of capacity W

int fractionalKnapsack(vector<int> val, vector<int> wt, int W)
{
    for (int i = 0; i < val.size(); i++)
    {
        // Calculate value per weight for each item
        val[i] = val[i] / wt[i];
    }
    // Create a vector of pairs to store value and weight
    vector<pair<int, int>> items;
    for (int i = 0; i < val.size(); i++)
    {
        items.push_back(make_pair(val[i], wt[i]));
    }
    sort(items.begin(), items.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
             return a.first > b.first; // Sort by value per weight in descending order
         });
    int totalValue = 0; // Total value of knapsack
    for (auto &item : items)
    {
        if (W == 0) // If knapsack is full, break
            break;
        if (item.second <= W) // If item can be fully added
        {
            totalValue += item.first * item.second; // Add full value of the item
            W -= item.second;                       // Reduce remaining capacity
        }
        else // If only part of the item can be added
        {
            totalValue += item.first * W; // Add partial value
            W = 0;                        // Knapsack is now full
        }
    }
    return totalValue; // Return the total value of the knapsack
}

int main()
{
    vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int W = 50; // Capacity of knapsack
    cout << "Maximum value in Knapsack = " << fractionalKnapsack(value, weight, W) << endl;
}