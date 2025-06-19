#include <iostream>
#include <vector>
using namespace std;

int pow(int x, int n)
{
    if (n == 0)
        return 1; // Base case: x^0 = 1

    int halfPow = pow(x, n / 2); // Recursive call for n/2
    if (n % 2 == 0)
    {
        return halfPow * halfPow; // If n is even, return (x^(n/2))^2
    }
    else
    {
        return x * halfPow * halfPow; // If n is odd, return x * (x^(n/2))^2
    }
}

int main()
{
    int x, n;
    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;
    int result = pow(x, n);
    cout << x << "^" << n << " = " << result << endl;
    return 0;
}