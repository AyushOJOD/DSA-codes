#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<string> getSentence(string s)
    {
        vector<string> ans;
        string temp = "";

        for (char ch : s)
        {
            if (ch == " ")
            {
                ans.push_back(temp);
                temp = "";
            }
            else
            {
                temp += ch;
            }
        }

        ans.push_back(temp);
    }

public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        vector<string> s1 = getSentence(sentence1);
        vector<string> s2 = getSentence(sentence2);

        int n = s1.size(), m = s2.size();

        if (n < m)
        {
            swap(s1, s2);
        }

        int st = 0, en = 0;

        while (st < m && s1[st] == s2[st])
        {
            st++;
        }

        while (en < n2 && s1[n1 - en - 1] == s2[n1 - en - 1])
        {
            en++;
        }

        return st + en >= m;
    }
};

int main()
{

    return 0;
}