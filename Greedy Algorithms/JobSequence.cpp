#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Job
{
public:
    int profit;
    int deadline;
    int id;

    Job(int idx, int d, int p) : id(idx), profit(p), deadline(d) {}
};

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

int maxTotalProfitWithSequence(vector<int> profit, vector<int> deadline)
{
    int n = profit.size();
    vector<Job> jobs;

    // Create pairs of profit and deadline
    for (int i = 0; i < n; i++)
    {
        jobs.push_back(Job(i, deadline[i], profit[i]));
    }

    // Sort jobs based on profit in descending order
    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b)
         {
             return a.profit > b.profit; // Sort by profit descending
         });

    int Totalprofit = jobs[0].profit; // Start with the profit  of the first job
    cout << "Job ID: " << jobs[0].id << ", Profit: " << jobs[0].profit << ", Deadline: " << jobs[0].deadline << endl;
    int safeDeadline = jobs[0].deadline + 1; // Start with the deadline of the first job
    for (int i = 1; i < n; i++)
    {
        if (jobs[i].deadline >= safeDeadline)
        {
            Totalprofit = Totalprofit + jobs[i].profit;                                                                       // Add profit if the job can be scheduled
            safeDeadline = jobs[i].deadline + 1;                                                                              // Update the safe deadline
            cout << "Job ID: " << jobs[i].id << ", Profit: " << jobs[i].profit << ", Deadline: " << jobs[i].deadline << endl; // Print job details
        }
    }
    return Totalprofit; // Return the total profit
}

int main()
{
    vector<int> profit = {20, 10, 40, 30};
    vector<int> deadline = {4, 1, 1, 1};

    int maxProfit = maxTotalProfitWithSequence(profit, deadline);
    cout << "Maximum total profit: " << maxProfit << endl;

    return 0;
}