#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> vr;
    vector<int> vc;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                vr.push_back(i);
                vc.push_back(j);
            }
        }
    }

    for (int i = 0; i < vr.size(); i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[vr[i]][j] = 0;
        }
    }

    for (int i = 0; i < vc.size(); i++)
    {
        for (int j = 0; j < rows; j++)
        {
            matrix[j][vc[i]] = 0;
        }
    }
}

int main()
{

    return 0;
}