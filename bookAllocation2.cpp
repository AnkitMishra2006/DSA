#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedpages){
    int stu = 1, pages = 0;
    for(int i = 0; i< n; i++){
        if(arr[i] > maxAllowedpages) return false; // if a book has more pages than allowed, it's invalid

        if(pages + arr[i] <= maxAllowedpages){
            pages += arr[i]; // add pages to current student
        } else {
            stu++; // allocate to next student
            pages = arr[i]; // start with current book for new student
        }
    }
    return stu <= m; // check if the number of students used is within limit
}

int allocateBooks(vector<int> &arr, int n, int m ){
    if(m>n) return -1; // more students than books
    if(m == 0 || n == 0) return 0; // no students or no books
    int ans = -1;

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    int st = *max_element(arr.begin(), arr.end()), end = sum;

    while(st <= end){
        int mid = st + (end-st)/2;
        if(isValid(arr, n, m, mid)){
            ans = mid;
            end = mid - 1; // try to find a smaller maximum
        } else {
            st = mid + 1; // increase the minimum maximum
        }
    }
    return ans;
}

int main(){

    vector<int> arr = {2,1,3,4};
    int n = 4, m = 2;

    cout << "Minimum number of pages allocated to a student is: " << allocateBooks(arr, n, m) << endl;
    return 0;
}