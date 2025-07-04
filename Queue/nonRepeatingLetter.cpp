#include <iostream>
#include <queue>
using namespace std;

int main()
{
    string str = "aabccxb";
    queue<char> q;
    int freq[26] = {0}; // Frequency array for 26 lowercase letters
    char ans;
    for (char ch : str)
    {
        q.push(ch);
        freq[ch - 'a']++;

        // Remove elements from the front of the queue if they are not unique
        while (!q.empty() && freq[q.front() - 'a'] > 1)
        {
            q.pop();
        }

        // If the queue is empty, print '-1', otherwise print the front element
        if (q.empty())
        {
            ans = -1;
        }
        else
        {
            ans = q.front();
        }
    }

    cout << "First non-repeating character: " << ans << endl;

    return 0;
}