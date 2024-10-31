#include <bits/stdc++.h>
using namespace std;

class Solution
{
#define MAX 10000000000000000LL
    typedef long long ll;

public:
    ll helper(vector<int> &robots, int robo_pos, vector<int> &factories, int fact_pos, vector<vector<ll>> &dp)
    {
        if (robo_pos < 0)
        {
            return 0;
        }
        if (fact_pos < 0)
        {
            return MAX;
        }

        if (dp[robo_pos][fact_pos] != -1)
        {
            return dp[robo_pos][fact_pos];
        }

        ll take = abs(robots[robo_pos] - factories[fact_pos]) + helper(robots, robo_pos - 1, factories, fact_pos - 1, dp);

        ll notTake = helper(robots, robo_pos, factories, fact_pos - 1, dp);

        return dp[robo_pos][fact_pos] = min(take, notTake);
    }

    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factories;

        for (auto it : factory)
        {
            int pos = it[0];
            int cnt = it[1];

            for (int i = 0; i < cnt; i++)
            {
                factories.push_back(pos);
            }
        }

        vector<vector<ll>> dp(robot.size(), vector<ll>(factories.size(), -1));

        return helper(robot, robot.size() - 1, factories, factories.size() - 1, dp);
    }
};

int main()
{

    return 0;
}