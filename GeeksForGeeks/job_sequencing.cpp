#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

class Solution
{
private:
    static bool comp(Job j1, Job j2)
    {
        return j1.profit > j2.profit;
    }

public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        sort(arr, arr + n, comp);

        int totalProfit = 0, maxDeadline = -1, cnt = 0;

        for (int i = 0; i < n; i++)
        {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }

        vector<int> hash(maxDeadline + 1, -1);

        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j >= 0; j++)
            {
                if (hash[j] == -1)
                {
                    cnt++;
                    hash[j] = arr[i].id;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }

        return {cnt, totalProfit};
    }
};

int main()
{

    return 0;
}