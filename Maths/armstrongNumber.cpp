#include <iostream>
#include <cmath>
using namespace std;

// Function to find whether a number is an Armstrong number
bool isArmstrong(int n)
{
    int original = n, sum = 0, digits = 0;

    // Count the number of digits
    while (original != 0)
    {
        original /= 10;
        digits++;
    }

    original = n;

    // Calculate the sum of the digits raised to the power of the number of digits
    while (original != 0)
    {
        int digit = original % 10;
        sum += pow(digit, digits);
        original /= 10;
    }

    // Check if the sum is equal to the original number
    return sum == n;
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (isArmstrong(number))
    {
        cout << number << " is an Armstrong number." << endl;
    }
    else
    {
        cout << number << " is not an Armstrong number." << endl;
    }

    return 0;
}