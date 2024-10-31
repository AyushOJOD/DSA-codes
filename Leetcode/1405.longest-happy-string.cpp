#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        string res = "";

        priority_queue<pair<int, char>> pq;
        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});

        while (!pq.empty())
        {
            auto it1 = pq.top();
            pq.pop();

            int cnt1 = it1.first;
            int ch1 = it1.second;

            if (res.length() >= 2 && res.back() == ch1 && res[res.length() - 2] == ch1)
            {
                if (pq.empty())
                {
                    break;
                }

                auto it2 = pq.top();
                pq.pop();

                int cnt2 = it2.first;
                int ch2 = it2.second;

                res += ch2;
                cnt2--;

                if (cnt2 > 0)
                {
                    pq.push({cnt2, ch2});
                }

                pq.push({cnt1, ch1});
            }
            else
            {
                res += ch1;
                cnt1--;

                if (cnt1 > 0)
                {
                    pq.push({cnt1, ch1});
                }
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}