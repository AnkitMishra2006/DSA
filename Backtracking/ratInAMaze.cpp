#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans, vector<vector<bool>> &vis)
{
    int n = mat.size();
    if (r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || vis[r][c] == true)
    {
        return; // Out of bounds or blocked cell
    }
    if (r == n - 1 && c == n - 1)
    {
        ans.push_back(path); // Reached the destination
        return;
    }

    // Mark the cell as visited
    vis[r][c] = true;

    // down
    helper(mat, r + 1, c, path + 'D', ans, vis);
    // up
    helper(mat, r - 1, c, path + 'U', ans, vis);
    // left
    helper(mat, r, c - 1, path + 'L', ans, vis);
    // right
    helper(mat, r, c + 1, path + 'R', ans, vis);

    vis[r][c] = false; // Backtrack: unmark the cell
}

vector<string> findPath(vector<vector<int>> &mat)
{

    int n = mat.size();

    vector<string> ans;
    string path = "";
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    helper(mat, 0, 0, path, ans, vis);

    return ans;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    vector<string> paths = findPath(mat);

    for (const string &path : paths)
    {
        cout << path << endl;
    }

    return 0;
}