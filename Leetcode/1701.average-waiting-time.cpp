#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        int n = customers.size();

        int waitTime = 0, currTime = customers[0][0];

        for (auto it : customers)
        {
            if (it[0] > currTime)
            {
                currTime = it[0];
            }

            waitTime += (currTime + it[1]) - it[0];
            currTime += it[1];
        }

        return static_cast<double>(waitTime) / n;
    }
};

int main()
{

    return 0;
}