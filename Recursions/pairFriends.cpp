#include <iostream>
using namespace std;

int pairFriends(int n)
{
    if (n == 1 || n == 2)
    {
        return n;
    }

    return pairFriends(n - 1) + (n - 1) * pairFriends(n - 2);
}

int main()
{
    int n;
    cout << "Enter the number of friends: ";
    cin >> n;

    int ways = pairFriends(n);
    cout << "Number of ways to pair " << n << " friends: " << ways << endl;

    return 0;
}