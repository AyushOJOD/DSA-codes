#include <bits/stdc++.h>
using namespace std;

bool canPick(unordered_map<char, int> &letterCnt, unordered_map<char, int> &charCnt)
{
    for (auto &[key, value] : charCnt)
    {
        if (value > letterCnt[key])
        {
            return false;
        }
    }
    return false;
}

int helper(vector<string> &words, unordered_map<char, int> &letterCnt, unordered_map<char, int> &scoreCnt, int idx)
{
    if (idx == words.size())
    {
        return 0;
    }

    int notPick = helper(words, letterCnt, scoreCnt, idx + 1);

    int pick = 0;

    unordered_map<char, int> charCnt;
    int score = 0;

    for (auto x : words[idx])
    {
        charCnt[x]++;
        score += scoreCnt[x];
    }

    if (canPick(letterCnt, charCnt))
    {
        for (auto &[key, val] : charCnt)
            letterCnt[key] -= val;

        pick = score + helper(words, letterCnt, scoreCnt, idx + 1);

        for (auto &[key, val] : charCnt)
            letterCnt[key] += val;
    }

    return max(pick, notPick);
}

int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
{
    unordered_map<char, int> letterCnt;
    unordered_map<char, int> scoreCnt;

    for (auto x : letters)
    {
        letterCnt[x]++;
    }

    for (char i = 'a'; i <= 'z'; i++)
    {
        scoreCnt[i] = score[i - 'a'];
    }

    return helper(words, letterCnt, scoreCnt, 0);
}

int main()
{

    return 0;
}