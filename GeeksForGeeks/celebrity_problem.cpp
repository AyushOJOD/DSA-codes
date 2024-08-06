#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int celeb = 0;

        // Step 1: Find a candidate for celebrity
        for (int i = 1; i < n; i++)
        {
            if (mat[celeb][i] == 1)
            {
                // If celeb knows i, then celeb cannot be the celebrity
                celeb = i;
            }
        }

        // Step 2: Verify the candidate
        for (int i = 0; i < n; i++)
        {
            if (i != celeb && (mat[celeb][i] == 1 || mat[i][celeb] == 0))
            {
                // celeb should not know i, and everyone should know celeb
                return -1;
            }
        }

        return celeb;
    }
};

int main()
{

    return 0;
}