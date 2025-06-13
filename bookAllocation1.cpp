#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> arr, int maxPages, int k)
{
    int n = arr.size();
    int stud = 1, pagesStud = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesStud + arr[i] <= maxPages)
        {
            pagesStud += arr[i];
        }
        else
        {
            stud++;
            pagesStud = arr[i];
        }
    }

    return (stud <= k);
}

int splitArray(vector<int> &nums, int k)
{

    if (nums.size() < k)
        return -1;
    int low = *(max_element(nums.begin(), nums.end()));
    int high = accumulate(nums.begin(), nums.end(), 0);

    for (int i = low; i <= high; i++)
    {
        if (check(nums, i, k))
            return i;
    }
    return -1;
}
