#include <iostream>
#include <string>
using namespace std;

void removeDuplicates(string str, int i, bool map[26], string ans)
{
    if (i == str.length())
    {
        cout << "ans : " << ans << endl;
        return;
    }

    int mapIdx = (int)(str.at(i) - 'a');

    if (map[mapIdx])
    {
        removeDuplicates(str, i + 1, map, ans);
    }
    else
    {
        map[mapIdx] = true;
        removeDuplicates(str, i + 1, map, ans + str.at(i));
    }
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    bool map[26] = {false}; // Initialize a boolean array to track characters
    removeDuplicates(str, 0, map, "");

    return 0;
}