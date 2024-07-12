#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution
{
public:
    long long maximumPoints(vector<int> &enemyEnergies, int currentEnergy)
    {
        int n = enemyEnergies.size();
        ll points = 0;

        sort(enemyEnergies.begin(), enemyEnergies.end());

        int left = 0, right = n - 1;

        while (left <= right)
        {
            if (enemyEnergies[left] > currentEnergy)
            {
                if (points == 0)
                {
                    return 0;
                }

                while (currentEnergy < enemyEnergies[left])
                {
                    currentEnergy += enemyEnergies[right];
                    right--;
                }
            }
            else
            {
                int diff = currentEnergy / enemyEnergies[left];
                currentEnergy = currentEnergy % enemyEnergies[left];
                points += diff;
            }
        }
        return points;
    }
};

int main()
{

    return 0;
}