#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool doesAliceWin(string s)
    {
        int cnt = 0;

        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};

        for (char &ch : s)
        {
            if (st.find(ch) != st.end())
            {
                cnt++;
            }
        }

        if (cnt == 0)
        {
            return false;
        }

        int ans = 0;

        while (cnt > 0)
        {
            int alice = 0;
            while (alice < cnt && alice % 2 != 0)
            {
                alice++;
            }
            cnt = cnt - alice;
            int bob = 0;
            while (bob < cnt && bob % 2 == 0)
            {
                bob++;
            }
            cnt = cnt - bob;
        }
        if (cnt % 2 == 0)
            return true;
        else
            return false;
    }
};

int main()
{

    return 0;
}