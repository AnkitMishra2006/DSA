#include <iostream>
using namespace std;

bool checkPrime(int n)
{
    int count = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (count > 2) // If more than 2 divisors found, it's not prime
            return false;
        if (n % i == 0)
        {
            count++;
            if (i != n / i) // To avoid printing the square root twice
            {
                count++;
            }
        }
    }
    return true; // If exactly 2 divisors found, it's prime
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (checkPrime(number))
    {
        cout << number << " is a prime number." << endl;
    }
    else
    {
        cout << number << " is not a prime number." << endl;
    }

    return 0;
}