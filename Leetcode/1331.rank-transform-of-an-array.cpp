#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<pair<int, int>> numWithIdx;

        for (int i = 0; i < arr.size(); i++)
        {
            numWithIdx.push_back({arr[i], i});
        }

        sort(numWithIdx.begin(), numWithIdx.end());

        vector<int> ans(arr.size(), -1);

        for (int i = 0; i < numWithIdx.size(); i++)
        {
            int idx = numWithIdx[i].second;

            ans[idx] = i + 1;
        }

        return ans;
    }
};

int main()
{

    return 0;
}