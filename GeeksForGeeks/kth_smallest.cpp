#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<int> &arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());

        if (k == 0)
        {
            return pq.top();
        }

        for (int i = 0; i < k - 1; i++)
        {
            pq.pop();
        }

        return pq.top();
    }
};

int main()
{

    return 0;
}