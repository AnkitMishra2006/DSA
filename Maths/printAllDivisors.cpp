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

void printAllDivisors2(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (i != n / i) // To avoid printing the square root twice
            {
                cout << n / i << " ";
            }
        }
    }
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    printAllDivisors2(number);

    return 0;
}