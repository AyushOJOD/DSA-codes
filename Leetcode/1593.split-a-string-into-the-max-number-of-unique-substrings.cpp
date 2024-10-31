#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void getMaxSubstr(string s, int idx, unordered_set<string> &st, int currCnt, int &maxCnt)
    {

        if (currCnt + (s.length() - idx) <= maxCnt)
        {
            return;
        }

        if (idx >= s.length())
        {
            maxCnt = max(maxCnt, currCnt);
            return;
        }

        for (int j = idx; j < s.length(); j++)
        {
            string sub = s.substr(idx, j - idx + 1);
            if (st.find(sub) == st.end())
            {
                st.insert(sub);
                getMaxSubstr(s, j + 1, st, currCnt + 1, maxCnt);
                st.erase(sub);
            }
        }
    }

public:
    int maxUniqueSplit(string s)
    {
        unordered_set<string> st;
        int currCnt = 0, maxCnt = 0, i = 0;

        getMaxSubstr(s, i, st, currCnt, maxCnt);

        return maxCnt;
    }
};

int main()
{

    return 0;
}