#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int left_right = 0, right_left = 0;

    for (int i = 0; i < n; i++)
    {
        left_right += grid[i][i];
        right_left += grid[i][n - i - 1];
    }

    int total = left_right + right_left;

    if (n % 2 == 0)
    {
        cout << total << endl;
    }
    else
    {
        total -= grid[n / 2][n / 2];
        cout << total << endl;
    }

    return 0;
}