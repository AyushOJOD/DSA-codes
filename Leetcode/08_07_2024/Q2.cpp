#include <bits/stdc++.h>
using namespace std;

int findWinningPlayer(vector<int> &skills, int k)
{
    int n = skills.size();
    if (k >= n - 1)
    {
        int maxi = max_element(skills.begin(), skills.end()) - skills.begin();
        return maxi;
    }

    int consWins = 0;
    int curr = 0;

    queue<int> index;
    for (int i = 1; i < n; ++i)
    {
        index.push(i);
    }

    while (consWins < k)
    {
        int next = index.front();
        index.pop();

        if (skills[curr] > skills[next])
        {
            consWins++;
            index.push(next);
        }
        else
        {
            consWins = 1;
            index.push(curr);
            curr = next;
        }
    }

    return curr;
}

int main()
{

    return 0;
}