#include <iostream>
#include <vector>
using namespace std;

// Intersection of two sorted arrays
// Duplicate elements are also included in the intersection
vector<int> intersectionOfSortedArrays(vector<int> a, vector<int> b)
{
    int n1 = a.size();
    int n2 = b.size();
    vector<int> intersection;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            // Found a common element
            intersection.push_back(a[i]);
            i++;
            j++;
        }
    }
    return intersection;
}

int main()
{
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 2, 3, 5};

    vector<int> intersection = intersectionOfSortedArrays(a, b);

    for (int num : intersection)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}