#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> actualTime;

        for (string s : timePoints)
        {
            string s1 = s[0] + s[1];
            string s2 = s[3] + s[4];

            int t1 = stoi(s1) * 60;
            int t2 = stoi(s2);

            int time = t1 + t2;

            actualTime.push_back(time);
        }

        sort(actualTime.begin(), actualTime.end());

        int minDiff = INT_MAX;

        for (int i = 1; i < actualTime.size(); i++)
        {
            int currDiff =
        }
    }
};

int main()
{

    return 0;
}