#include <iostream>
#include <string>
using namespace std;

void binStrings(int n, string ans, int lastPlace)
{
    if (n == 0)
    {
        cout << ans << endl;
        return;
    }

    if (lastPlace != 0) // Last place was 0, we can add either 0 or 1
    {
        binStrings(n - 1, ans + "0", 0); // Add 0
        binStrings(n - 1, ans + "1", 1); // Add 1
    }
    else // Last place was 1, we can only add 0
    {
        binStrings(n - 1, ans + "0", 0); // Add 0
    }
}

int main()
{
    int n;
    cout << "Enter the length of binary strings: ";
    cin >> n;

    cout << "Binary strings of length " << n << " are:" << endl;
    binStrings(n, "", 0);

    return 0;
}