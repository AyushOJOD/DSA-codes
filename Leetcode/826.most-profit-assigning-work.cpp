#include <bits/stdc++.h>
using namespace std;

int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
{
    sort(worker.begin(), worker.end(), greater<int>());

    int maxProfit = 0;

    int w = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //{profit, difficulty}

    for (int i = 0; i < profit.size(); i++)
    {
        pq.push({profit[i], difficulty[i]});
    }

    while (!pq.empty() && w < worker.size())
    {
        auto it = pq.top();
        int profitVal = it.first;
        int difficultyVal = it.second;

        // Check if the current worker can handle the difficulty
        if (difficultyVal <= worker[w])
        {
            while (w < worker.size() && difficultyVal <= worker[w])
            {
                maxProfit += profitVal;
                w++;
            }
        }
        else
        {
            pq.pop();
        }
    }

    return maxProfit;
}

int main()
{

    return 0;
}