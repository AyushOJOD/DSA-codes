#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {

        int curr = 0, maxAlt = curr;

        for (int i = 0; i < gain.size(); i++)
        {
            curr += gain[i];
            maxAlt = max(maxAlt, curr);
        }

        return maxAlt;
    }
};

int main()
{

    return 0;
}