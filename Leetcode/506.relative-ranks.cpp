#include <bits/stdc++.h>
using namespace std;

vector<string> findRelativeRanks(vector<int> &score)
{
    vector<string> rank(score.size());

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < score.size(); i++)
    {
        pq.push({score[i], i});
    }
    int i = 0;

    while (!pq.empty())
    {
        rank[pq.top().second] = i == 0 ? "Gold Medal" : i == 1 ? "Silver Medal"
                                                    : i == 2   ? "Bronze Medal"
                                                               : to_string(i + 1);

        i++;
        pq.pop();
    }
    return rank;
}

int main()
{

    return 0;
}