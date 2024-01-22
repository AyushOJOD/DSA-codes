#include <bits/stdc++.h>
using namespace std;

int numSpecial(vector<vector<int>> &mat)
{
    int count = 0;
    int m = mat.size();
    int n = mat[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{

    return 0;
}