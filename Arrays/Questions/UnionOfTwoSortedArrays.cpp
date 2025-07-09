#include <iostream>
#include <vector>
using namespace std;

vector<int> mergedArray(vector<int> a, vector<int> b)
{
    int n1 = a.size();
    int n2 = b.size();

    int i = 0;
    int j = 0;
    vector<int> merged;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            if (merged.empty() || merged.back() != a[i])
            {
                merged.push_back(a[i]);
                i++;
            }
        }
        else if (a[i] > b[j])
        {
            if (merged.empty() || merged.back() != b[j])
            {
                merged.push_back(b[j]);
                j++;
            }
        }
        else
        {
            if (merged.empty() || merged.back() != a[i])
            {
                merged.push_back(a[i]);
                i++;
                j++;
            }
        }
    }
    while (i < n1)
    {
        if (merged.empty() || merged.back() != a[i])
        {
            merged.push_back(a[i]);
        }
        i++;
    }
    while (j < n2)
    {
        if (merged.empty() || merged.back() != b[j])
        {
            merged.push_back(b[j]);
        }
        j++;
    }
    return merged;
}

int main()
{
    vector<int> arr1 = {1, 1, 3, 5, 7};
    vector<int> arr2 = {2, 2, 3, 4, 6, 8};

    vector<int> result = mergedArray(arr1, arr2);

    cout << "Merged Array: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}