#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> res;
        bool rowCheck = false, colCheck = false;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                int minInRow = *min_element(matrix[row].begin(), matrix[col].end());

                if (minInRow == matrix[row][col])
                {
                    rowCheck = true;
                }

                int maxInCol = INT_MIN;

                for (int i = 0; i < n; i++)
                {
                    if (matrix[i][col] > maxInCol)
                    {
                        maxInCol = matrix[i][col];
                    }
                }

                if (maxInCol == matrix[row][col])
                {
                    colCheck = true;
                }

                if (rowCheck && colCheck)
                {
                    res.push_back(matrix[row][col]);
                }
                rowCheck = false, colCheck = false;
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}