#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// maximize the profit by selecting jobs based on their profit and deadlines
int maxTotalProfit(vector<int> profit, vector<int> deadline)
{
    int n = profit.size();
    vector<pair<int, int>> jobs;

    // Create pairs of profit and deadline
    for (int i = 0; i < n; i++)
    {
        jobs.push_back(make_pair(deadline[i], profit[i]));
    }

    // Sort jobs based on profit in descending order
    sort(jobs.begin(), jobs.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
             return a.second > b.second; // sort by profit
         });

    int Totalprofit = jobs[0].second;     // Start with the profit  of the first job
    int safeDeadline = jobs[0].first + 1; // Start with the deadline of the first job
    for (int i = 1; i < n; i++)
    {
        if (jobs[i].first >= safeDeadline)
        {
            Totalprofit = Totalprofit + jobs[i].second; // Add profit if the job can be scheduled
            safeDeadline = jobs[i].first + 1;           // Update the safe deadline
        }
    }
    return Totalprofit; // Return the total profit
}

int main()
{
    vector<int> profit = {20, 10, 40, 30};
    vector<int> deadline = {4, 1, 1, 1};

    int maxProfit = maxTotalProfit(profit, deadline);
    cout << "Maximum total profit: " << maxProfit << endl;

    return 0;
}