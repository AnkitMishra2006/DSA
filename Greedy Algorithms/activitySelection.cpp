#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
//  The activities are given as pairs of start and end times.

int activitySelection(vector<int> startTime, vector<int> endTime)
{
    int count = 1; // Count the first activity
    int currEndTime = 0;
    int n = startTime.size();
    for (int i = 1; i < n; i++)
    {
        if (startTime[i] >= currEndTime)
        {
            count++;
            currEndTime = endTime[i];
        }
    }
    return count; // +1 for the first activity
}

int activitySelectionUsingPairs(vector<int> startTime, vector<int> endTime)
{
    vector<pair<int, int>> activities;
    for (int i = 0; i < startTime.size(); i++)
    {
        activities.push_back({startTime[i], endTime[i]});
    }

    // Sort activities based on end time (which is now second)
    sort(activities.begin(), activities.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
             return a.second < b.second; // sort by endTime
         });

    int count = 1; // First activity is always selected
    int currEndTime = activities[0].second;

    for (int i = 1; i < activities.size(); i++)
    {
        if (activities[i].first >= currEndTime)
        {
            count++;
            currEndTime = activities[i].second;
        }
    }

    return count;
}

int main()
{
    vector<int> startTime = {1, 3, 0, 5, 8, 5};
    vector<int> endTime = {2, 4, 6, 7, 9, 9};

    int maxActivities = activitySelectionUsingPairs(startTime, endTime);
    cout << "Maximum number of activities that can be performed: " << maxActivities << endl;

    return 0;
}