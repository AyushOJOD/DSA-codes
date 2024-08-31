#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isCircle(int N, vector<string> A)
    {
        vector<vector<int>> adj(n, -1);

        unordered_map<char, vector<int>> startChar;

        for (int i = 0; i < n; i++)
        {
            char start = A[i][0];
            startChar[start].push_back(i);
        }

        for (int i = 0; i < n; i++)
        {
            char end = A[i][A[i].length() - 1];

            if (startChar.find(end) != startChar.end())
            {
                vector<int> curr = startChar[end];

                for (int idx = 0; idx < curr.size(); idx++)
                {
                    adj[i].push_back(curr[idx]);
                }
            }
        }
    }
};

int main()
{

    return 0;
}