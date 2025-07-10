#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minAbsDifference(vector<int> a, vector<int> b)
{
    // Sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int n = a.size();
    int absDiff = -1;
    for (int i = 0; i < n; i++)
    {
        if (absDiff == -1)
        {
            absDiff = 0;
        }
        // Calculate absolute difference between corresponding elements
        absDiff += abs(a[i] - b[i]);
    }
    return absDiff; // Return the total absolute difference
}

int main()
{
    vector<int> a = {1, 2, 3};
    vector<int> b = {2, 1, 3};
    cout << "Minimum Absolute Difference: " << minAbsDifference(a, b) << endl;
    return 0;
}