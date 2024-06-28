#include <bits/stdc++.h>
using namespace std;

bool canPlaceMyBalls(int mid, vector<int> &position, int m)
{
    int ballsPlaced = 1, prevBall = position[0];

    for (int i = 1; i < position.size(); i++)
    {
        if (position[i] - prevBall >= m)
        {
            ballsPlaced++;
            prevBall = position[i];
        }
    }

    return (ballsPlaced >= m);
}

int maxDistance(vector<int> &position, int m)
{
    sort(position.begin(), position.end());

    int left = 0, right = *max_element(position.begin(), position.end()), ans = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (canPlaceMyBalls(mid, position, m))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return ans;
}

int main()
{

    return 0;
}