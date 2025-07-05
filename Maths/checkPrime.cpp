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

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (isPrime(number))
    {
        cout << number << " is a prime number." << endl;
    }
    else
    {
        cout << number << " is not a prime number." << endl;
    }

    return 0;
}