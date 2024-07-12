#include <bits/stdc++.h>
using namespace std;

class Solution
{
    struct TrieNode
    {
        TrieNode *children[26];
        int idx;
    };

    TrieNode *getNode()
    {
        TrieNode *newNode = new TrieNode();

        newNode->idx = -1;

        for (int i = 0; i < 26; i++)
        {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        TrieNode *root = getNode();

        unordered_map<int, int> mp;

        for (int i = 0; i < words.size(); i++)
        {
            TrieNode *curr = root;

            for (char &ch : words[i])
            {
                if (curr->children[ch - 'a'] == NULL)
                {
                    curr->children[ch - 'a'] = getNode();
                }
                curr = curr->children[ch - 'a'];
            }

            if (curr->idx == -1)
            {
                curr->idx = i;
            }

            mp[curr->idx]++;
        }

        priority_queue<pair<int, int>> pq;

        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }

        vector<string> res;

        while (k > 0 && !pq.empty())
        {
            auto it = pq.top();

            int idx = it.second;

            res.push_back(words[idx]);

            k--;
        }
    }
};

int main()
{

    return 0;
}