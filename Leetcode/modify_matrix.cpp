#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    vector<int> maxVal(col, INT_MIN);
    for (int j = 0; j < col; ++j)
    {
        for (int i = 0; i < row; ++i)
        {
            if (matrix[i][j] > maxVal[j])
            {
                maxVal[j] = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = maxVal[j];
            }
        }
    }

    return matrix;
}

int main()
{

    return 0;
}
