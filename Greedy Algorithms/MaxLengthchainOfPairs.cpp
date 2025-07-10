#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the maximum length of chain of pairs just like activity selection problem

int maxLengthChain(vector<int> startLength, vector<int> endLength)
{
    vector<pair<int, int>> activities;
    for (int i = 0; i < startLength.size(); i++)
    {
        activities.push_back({startLength[i], endLength[i]});
    }

    // Sort activities based on end time (which is now second)
    sort(activities.begin(), activities.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
             return a.second < b.second; // sort by endLength
         });

    // First activity is always selected
    int length = activities[0].second - activities[0].first;

    for (int i = 1; i < activities.size(); i++)
    {
        if (activities[i].first >= activities[i - 1].second)
        {
            length += activities[i].second - activities[i].first; // Add the length of the current activity
        }
    }

    return length;
}

int main()
{
    vector<int> startLength = {5, 39, 5, 27, 50};
    vector<int> endLength = {24, 60, 28, 40, 90};

    int maxChains = maxLengthChain(startLength, endLength);
    cout << "Maximum length of chain of pairs: " << maxChains << endl;

    return 0;
}