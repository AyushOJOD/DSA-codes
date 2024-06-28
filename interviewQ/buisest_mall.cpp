// The Westfield Mall management is trying to figure out what the busiest moment at the mall was last year. You’re given data extracted from the mall’s door detectors. Each data point is represented as an integer array whose size is 3. The values at indices 0, 1 and 2 are the timestamp, the count of visitors, and whether the visitors entered or exited the mall (0 for exit and 1 for entrance), respectively. Here’s an example of a data point: [ 1440084737, 4, 0 ].

// Given an array, data, of data points, write a function findBusiestPeriod that returns the time at which the mall reached its busiest moment last year.

#include <bits/stdc++.h>
using namespace std;

int findBusiestPeriod(const vector<vector<int>> &data)
{
    // your code goes here

    int maxPopulation = INT_MIN;
    int maxTime = 0;
    int currPopulation = 0;

    for (int i = 0; i < data.size(); i++)
    {
        int currTime = data[i][0];
        int visitors = data[i][1];
        int isEntering = data[i][2];

        if (isEntering)
        {
            currPopulation += visitors;
        }
        else
        {
            currPopulation -= visitors;
        }

        if (i == data.size() - 1 || data[i + 1][0] != currTime)
        {
            if (currPopulation > maxPopulation)
            {
                maxPopulation = currPopulation;
                maxTime = currTime;
            }
        }

        return maxTime;
    }

    return maxTime;
}

int main()
{

    return 0;
}