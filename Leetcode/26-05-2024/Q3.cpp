#include <bits/stdc++.h>
using namespace std;

long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    unordered_map<int, int> val;
    long long cnt = 0;

    for (int num : nums2)
        val[num]++;

    for (int num1 : nums1)
    {
        for (int d = 1; d <= sqrt(num1); ++d)
        {
            if (num1 % d == 0)
            {
                int q1 = d;
                int q2 = num1 / d;

                if (q1 % k == 0)
                {
                    int req = q1 / k;
                    if (val.find(req) != val.end())
                        cnt += val[req];
                }

                if (q2 % k == 0 && q1 != q2)
                {
                    int req = q2 / k;
                    if (val.find(req) != val.end())
                        cnt += val[req];
                }
            }
        }
    }

    return cnt;
        
}

int main()
{

    return 0;
}
