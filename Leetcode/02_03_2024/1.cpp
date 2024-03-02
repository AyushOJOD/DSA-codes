#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums, int k)
{
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < nums.size(); i++)
    {
        pq.push(nums[i]);
    }

    int res = 0;

    while (pq.top() < k)
    {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();

        pq.push((2 * first) + second);

        res++;
    }

    return res;
}

int main()
{

    return 0;
}