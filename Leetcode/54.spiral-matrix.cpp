#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> res;

    int maxR = n - 1, minR = 0, maxC = m - 1, minC = 0;

    while (maxR >= minR && maxC >= minC)
    {
        for (int i = minC; i <= maxC; i++)
        {
            res.push_back(matrix[minR][i]);
        }
        minR++;

        if (minR > maxR || minC > maxC)
            break;

        for (int i = minR; i <= maxR; i++)
        {
            res.push_back(matrix[i][maxC]);
        }
        maxC--;

        if (minR > maxR || minC > maxC)
            break;

        for (int i = maxC; i >= minC; i--)
        {
            res.push_back(matrix[maxR][i]);
        }
        maxR--;
        if (minR > maxR || minC > maxC)
            break;

        for (int i = maxR; i >= minR; i--)
        {
            res.push_back(matrix[i][minC]);
        }
        minC++;
    }

    return res;
}

int main()
{

    return 0;
}