#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Minimum number of coins required to make a given amount using Indian coins
int minCoins(int amt, vector<int> coins)
{
    int result = 0;
    sort(coins.begin(), coins.end(), greater<int>()); // Sort coins in descending order
    for (int coin : coins)
    {
        if (amt == 0) // If no amount is left, break the loop
            break;
        else if (amt >= coin)
        {
            result += (amt / coin); // Count how many coins of this denomination can be used
            amt %= coin;            // Update the remaining amount
        }
    }
    return result; // Return the total number of coins used
}

int main()
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500}; // Indian coin denominations
    int amount = 1234;                                   // Amount to be made

    int result = minCoins(amount, coins);
    cout << "Minimum number of coins required: " << result << endl;

    return 0;
}