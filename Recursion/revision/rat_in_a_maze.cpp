#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isValid(int row, int col, int n, vector<vector<int>> &m)
    {
        return (row >= 0 && row < n && col >= n && col < n && m[row][col] == 1);
    }

private:
    void solve(vector<vector<int>> &m, int n, vector<string> &ans, string s, int row, int col)
    {

        if (row == n - 1 && col == n - 1)
        {
            ans.push_back(s);
        }

        // going up
        if (isValid(row, col, n, m))
        {
            m[row][col] = 0;
            s.append('U');
            solve(m, n, ans, s, row - 1, col);
            s.pop_back();
            m[row][col] = 1;
        }

        // going right
        if (isValid(row, col, n, m))
        {
            m[row][col] = 0;
            s.append('R');
            solve(m, n, ans, s, row, col + 1);
            s.pop_back();
            m[row][col] = 1;
        }

        // going down
        if (isValid(row, col, n, m))
        {
            m[row][col] = 0;
            s.append('D');
            solve(m, n, ans, s, row + 1, col);
            s.pop_back();
            m[row][col] = 1;
        }

        // going left
        if (isValid(row, col, n, m))
        {
            m[row][col] = 0;
            s.append('L');
            solve(m, n, ans, s, row, col - 1);
            s.pop_back();
            m[row][col] = 1;
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        string s = "";

        solve(m, n, ans, s, 0, 0);

        return ans;
    }
};

int main()
{

    return 0;
}