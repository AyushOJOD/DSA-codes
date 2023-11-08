#include<bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    int s_len = s.length();
    int p_len = p.length();

    if (s.size() < p.size())
        return {};

    vector<int> p_val(26, 0);
    vector<int> win(26, 0);

    for (int i = 0; i < p_len; i++)
    {
        p_val[p[i] - 'a']++;
        win[s[i] - 'a']++;
    }

    vector<int> ans;
    if (p_val == win)
        ans.push_back(0);

    for (int i = p_len; i < s_len; i++)
    {
        win[s[i - p_len] - 'a']--;
        win[s[i] - 'a']++;

        if (p_val == win)
            ans.push_back(i - p_len + 1);
    }
    return ans;
}

int main(){

    return 0;
}