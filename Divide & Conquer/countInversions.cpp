#include <iostream>
#include <vector>
using namespace std;

// Inversion: i < j and arr[i] > arr[j]

int merge(vector<int> &arr, int st, int mid, int end)
{

    vector<int> temp;
    int i = st, j = mid + 1;
    int invCount = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);

            invCount += (mid - i + 1); // All elements from i to mid are greater than arr[j]
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= end)
    {
        temp.push_back(arr[j++]);
    }
    // Copy back to original array
    for (int idx = st, x = 0; idx <= end; idx++)
    {
        arr[idx] = temp[x++];
    }
    return invCount;
}

int mergeSort(vector<int> &temp, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;

        int leftInvCount = mergeSort(temp, st, mid);
        int rightInvCount = mergeSort(temp, mid + 1, end);

        int invCount = merge(temp, st, mid, end);

        return leftInvCount + rightInvCount + invCount;
    }

    return 0;
}

int main()
{
    vector<int> arr = {6, 3, 5, 2, 7};

    int ans = mergeSort(arr, 0, arr.size() - 1); 
    cout << "Number of inversions: " << ans << endl;

    return 0;
}