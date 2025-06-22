#include <iostream>
using namespace std;

int countWays(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    if (n == 2)
    {
        return 2;
    }
    if (n == 3)
    {
        return 3;
    }

    // vertical choice
    int ways1 = countWays(n - 1);

    // horizonal choice
    int ways2 = countWays(n - 2);

    return ways1 + ways2;
}

int main()
{
    while (true)
    {
        int n;
        cout << "Enter the length of the wall (or -1 to exit): ";
        cin >> n;

        if (n == -1)
        {
            break;
        }

        int result = countWays(n);
        cout << "Number of ways to tile a 2x" << n << " wall: " << result << endl;
    }

    return 0;
}