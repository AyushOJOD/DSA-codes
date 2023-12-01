#include <bits/stdc++.h>
using namespace std;

vector<int> findWordsContaining(vector<string> &words, char x)
{
    vector<int> ans;

    for (int i = 0; i, words.size(); i++)
    {
        int temp = words[i].find(x);
        if (temp != string::npos)
        {
            ans.push_back(i);
        }
    }

    return ans;
}

int main()
{

    return 0;
}