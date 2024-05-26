#include <bits/stdc++.h>
using namespace std;

vector<int> matchingCnt(int n, vector<string> &X)
{
    // code here
    vector<int> ans;

    for (int i = 0; i < X.size(); i++)
    {
        int cnt = 0;
        for (int j = i + 1; j < X.size(); j++)
        {
            for (int k = 0; k < X[i].size(); k++)
            {
                if (X[i][k] == X[j][k])
                {
                    cnt++;
                }
            }
        }
        ans.push_back(cnt);
    }

    return ans;
}

int main()
{

    return 0;
}