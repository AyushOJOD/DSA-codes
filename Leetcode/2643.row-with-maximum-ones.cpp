#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int findOnes(vector<int> &row)
    {
        int firstOne = lower_bound(row.begin(), row.end(), 1);

        return row.size() - firstOne;
    }

public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        int maxOnes = INT_MIN;

        for (int i = 0; i < mat[0].size(); i++)
        {
            maxOnes = max(maxOnes, findOnes(mat[i]));
        }

        return maxOnes;
    }
};

int main()
{

    return 0;
}