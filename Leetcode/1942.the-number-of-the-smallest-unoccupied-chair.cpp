#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef pair<int, int> P;
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        int n = times.size();

        priority_queue<P, vector<P>, greater<P>> occupied;   //{depart, chairIdx}
        priority_queue<int, vector<int>, greater<int>> free; // {freedChairIdx}

        int targetArrival = times[targetFriend][0];
        int chair = 0;

        sort(begin(times), end(times));

        for (int i = 0; i < n; i++)
        {
            int arrival = times[i][0];
            int depart = times[i][1];

            while (!occupied.empty() && occupied.top().first <= arrival)
            {
                free.push(occupied.top().second);
                occupied.pop();
            }

            if (free.empty())
            {
                occupied.push({depart, chair});
                if (arrival == targetArrival)
                {
                    return chair;
                }
                chair++;
            }
            else
            {
                int minChair = free.top();
                free.pop();

                if (arrival == targetArrival)
                {
                    return minChair;
                }
                occupied.push({depart, minChair});
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}