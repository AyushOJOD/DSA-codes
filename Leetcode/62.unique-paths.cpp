#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(int row, int col)
    {
        if (row = 0 && col == 0)
        {
            return 1;
        }

        if (row < 0 || col < 0)
        {
            return 0;
        }

        // go up
        int up = helper(row - 1, col);

        // go left
        int left = helper(row, col - 1);

        return left + up;
    }

public:
    int uniquePaths(int m, int n)
    {
        return helper(m - 1, n - 1);
    }
};

int main()
{

    return 0;
}