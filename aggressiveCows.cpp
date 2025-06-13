#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int N, int C, int minDist)
{
    int cows = 1, lastPos = arr[0];
    for (int i = 1; i < N; i++)
    {
        if (arr[i] - lastPos >= minDist)
        {
            cows++;
            lastPos = arr[i]; // place the cow at this position
        }
        if (cows == C) // if we have placed all cows
        {
            return true; // we can place C cows with at least minDist apart
        }
    }
    return false; // not enough cows can be placed with the given distance
}

int getDistance(vector<int> &arr, int N, int C)
{

    sort(arr.begin(), arr.end());

    int st = 1, end = arr[N - 1] - arr[0], ans = -1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isPossible(arr, N, C, mid))
        {
            ans = mid;
            st = mid + 1; // try to find a larger minimum distance
        }
        else
        {
            end = mid - 1; // reduce the search space
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 8, 4, 9};
    cout << "Maximum distance between cows is: " << getDistance(arr, arr.size(), 3) << endl;
    return 0;
}