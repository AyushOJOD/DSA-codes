#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
}

class Solution
{
public:
    int tour(petrolPump p[], int n)
    {
        int total_petrol = 0, total_distance = 0;

        for (int i = 0; i < n; i++)
        {
            total_distance += p[i].distance;
            total_petrol += p[i].petrol;
        }

        if (total_distance > total_petrol)
        {
            return -1;
        }

        int remaining_fuel = 0, ans = 0;

        for (int i = 0; i < n; i++)
        {
            remaining_fuel += p[i].petrol - p[i].distance;

            if (remaining_fuel < 0)
            {
                ans = i + 1;
                remaining_fuel = 0;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}