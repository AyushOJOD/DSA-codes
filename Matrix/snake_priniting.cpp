#include <bits/stdc++.h>
using namespace std;

void snakePrint(int arr[m][n])
{
    vector<int> res;

    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                res.push_back(arr[i][j]);
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                res.push_back(arr[i][j]);
            }
        }
    }

    for (auto i : res)
    {
        cout << i << " ";
    }
}

int main()
{
    int m

        return 0;
}