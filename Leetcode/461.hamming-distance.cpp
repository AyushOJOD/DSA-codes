#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int cnt_set_bits(int n)
    {
        int cnt = 0;

        while (n > 0)
        {
            cnt += n & 1;
            n = n >> 1;
        }

        return cnt;
    }

public:
    int hammingDistance(int x, int y)
    {
        if (x == 0)
            return cnt_set_bits(y);
        if (y == 0)
            return cnt_set_bits(x);

        int xorVal = x ^ y;
        return cnt_set_bits(xorVal);
    }
};

int main()
{

    return 0;
}