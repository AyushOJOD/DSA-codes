#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;
    vector<int> prevRow;

    for (int i = 0; i < numRows; i++)
    {
        vector<int> currRow(i + 1, 1);
        for (int j = 1; j < i; j++)
        {
            currRow[i] = prevRow[i - 1] + prevRow[i];
        }

        res.push_back(currRow);
        prevRow = currRow;
    }
    return res;
}

int main()
{

    return 0;
}