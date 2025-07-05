#include <iostream>
using namespace std;

// Function to print all divisors of a number
void printAllDivisors(int n)
{
    cout << "Divisors of " << n << " are: ";
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    printAllDivisors(number);

    return 0;
}