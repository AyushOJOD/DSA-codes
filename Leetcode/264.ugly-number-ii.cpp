#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;

    int nthUglyNumber(int n)
    {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        unordered_set<ll> vis;

        pq.push(1);
        vis.insert(1);

        ll val = 1;

        while (n > 0)
        {
            val = pq.top();
            pq.pop();
            n--;

            if (vis.find(val * 2) == vis.end())
            {
                pq.push(val * 2);
                vis.insert(val * 2);
            }
            if (vis.find(val * 3) == vis.end())
            {
                pq.push(val * 3);
                vis.insert(val * 3);
            }
            if (vis.find(val * 5) == vis.end())
            {
                pq.push(val * 5);
                vis.insert(val * 5);
            }
        }

        return val;
    }
};

int main()
{

    return 0;
}