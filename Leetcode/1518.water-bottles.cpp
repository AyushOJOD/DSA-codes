#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int curr = numBottles;
        int leftOver = 0;

        while (curr >= numExchange)
        {
            numBottles += curr / numExchange;

            leftOver += curr % numExchange;

            curr /= numExchange;
        }

        if (leftOver >= numExchange)
        {
            numBottles++;
        }

        return numBottles;
    }
};

int main()
{

    return 0;
}