#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{

    // intizalize the set and q
    queue<pair<string, int>> q; // {word, level}
    unordered_set<string> s(wordList.begin(), wordList.end());

    q.push({beginWord, 1});
    s.erase(beginWord);

    while (!q.empty())
    {
        string word = q.front().first;
        int level = q.front().second;
        q.pop();

        if (word == endWord)
        {
            return level;
        }

        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (s.find(word) != s.end())
                {
                    q.push({word, level + 1});
                    s.erase(word);
                }
            }
            word[i] = original;
        }
    }

    return 0;
}

int main()
{

    return 0;
}