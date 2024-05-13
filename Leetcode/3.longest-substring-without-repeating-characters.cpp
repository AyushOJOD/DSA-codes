#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)

{
    int res = 0, left = 0;
    unordered_set<int> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (st.find(s[i]) == st.end())
        {
            st.insert(s[i]);
            res = max(res, i - left + 1);
        }
        else
        {
            while (st.find(s[i]) != st.end())
            {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[i]);
        }
    }
    return res;
}

int main()
{

    return 0;
}