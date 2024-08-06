#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canMeasureWater(int x, int y, int target)
    {
        if (x + y < target)
            return false;
        return target % gcd(x, y) == 0;
    }
};

int main()
{

    return 0;
}