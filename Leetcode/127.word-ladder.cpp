#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{

    int len = beginWord.length();
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    unordered_set<string> st(wordList.begin(), wordList.end());

    if (st.find(beginWord) != st.end())
    {
        st.erase(beginWord);
    }

    while (!q.empty())
    {
        string word = q.front().first;
        int level = q.front().second;
        q.pop();

        if (word == targetWord)
            return level;

        for (int i = 0; i < len; i++)
        {
            char letter = word[i];

            for (char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;
                if (st.find(word) != st.end())
                {
                    st.erase(word);
                    q.push({word, level + 1});
                }
            }

            word[i] = letter;
        }
    }

    return 0;
}

int main()
{

    return 0;
}