#include <bits/stdc++.h>
using namespace std;

void solve(int idx, string temp, string s, unordered_set<string> &dict, vector<string> &ans)
{
    if (idx == s.size())
    {
        ans.push_back(temp);
        return;
    }

    string word = "";

    for (int j = 0; j < s.length(); j++)
    {
        word += s[j];
        if (dict.find(word) != dict.end())
        {
            solve(idx + 1, temp + word + (idx + 1 < s.length() ? " " : ""), s, dict, ans);
        }
    }
}

vector<string> wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    string temp = "";
    vector<string> ans;

    dfs(0, temp, s, dict, ans);
    return ans;
}

int main()
{

    return 0;
}