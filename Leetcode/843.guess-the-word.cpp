#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int num_of_matches(string &word1, string &word2)
    {
        int cnt = 0;
        for (int i = 0; i < 6; i++)
        {
            if (word1[i] == word2[i])
            {
                cnt++;
            }
        }
        return cnt;
    }

    void remove_words(string &checkWord, int matches, unordered_set<string> &set)
    {
        unordered_set<string> to_be_deleted;

        for (auto &word : set)
        {
            if (num_of_matches(word, checkWord) != matches)
            {
                to_be_deleted.insert(word);
            }
        }

        for (auto &word : to_be_deleted)
        {
            set.erase(word);
        }
    }

    void findSecretWord(vector<string> &words, Master &master)
    {
        unordered_set<string> set(words.begin(), words.end());

        while (!set.empty() && allowedGuesses > 0)
        {
            int matches = master.guess(*set.begin());
            remove_words(*set.begin(), matches, set);
            allowedGuesses--;
        }
        }
};

int main()
{

    return 0;
}