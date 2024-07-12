#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int helper(TrieNode *root, string target, string curr, int idx)
    {
        // base case

        // recursion
        int notTake = 0 + helper(root, target, curr, idx);
    }

    struct TrieNode
    {
        bool isEnd;
        TrieNode *children[26];
        int cost;
        string word;
    };

    TrieNode *getNode()
    {
        TrieNode *newNode = new TrieNode();

        newNode->cost = 0;
        newNode->isEnd = false;
        newNode->word = "";

        for (int i = 0; i < 26 i++)
        {
            newNode->children[i] = NULL;
        }

        return newNode;
    }

    void insert(int idx, string &word, TrieNode *root, vector<int> &costs)
    {
        TrieNode *curr = root;

        for (char &ch : word)
        {
            if (curr->children[ch - 'a'] == NULL)
            {
                curr->children[ch - 'a'] = getNode();
            }
            curr = curr->children[ch - 'a'];
        }

        curr->isEnd = true;
        curr->cost = costs[idx];
        curr->word = word;
    }

public:
    int minimumCost(string target, vector<string> &words, vector<int> &costs)
    {
        TrieNode *root = getNode();

        for (int i = 0; i < words.size(); i++)
        {
            insert(i, words[i], root, costs);
        }
    }
};

int main()
{

    return 0;
}