#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        unordered_map<char, int> mp;

        for (int i = 0; i < word.length(); i++)
        {
            mp[word[i]]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }

        int currPushes = 0;
        int curr_idx = 1;
        int buttonsUsed = 1;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int freq = it.first;
            currPushes += (freq * curr_idx);
            buttonsUsed++;

            if (buttonsUsed > 7)
            {
                curr_idx++;
                buttonsUsed = 1;
            }
        }

        return currPushes;
    }
};

int main()
{

    return 0;
}