#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    struct TrieNode
    {
        bool isEnd;
        TrieNode *children[26];
        int idxInContainer;
    };

    TrieNode *getNode()
    {
        TrieNode *newNode = new TrieNode();

        newNode->isEnd = false;
        newNode->idxInContainer = -1;

        for (int i = 0; i < 26; i++)
        {
            newNode->children[i] = NULL;
        }

        return newNode;
    }

    void insert(TrieNode *root, string &word, int idx)
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

        curr->idxInContainer = idx;
        curr->isEnd = true;
    }

public:
    vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery)
    {
        TrieNode *root = getNode();

        int minSizeIdx = wordsContainer[0].size();

        for (int i = 0; i < wordsContainer.size(); i++)
        {
            string word = wordsContainer[i];

            int size = word.size();

            minSizeIdx = min(minSizeIdx, size);

            reverse(word.begin(), word.end());

            insert(root, word, i);
        }

        vector<int> result;

        for (auto search : wordsQuery)
        {
            reverse(search.begin(), search.end());
            int currFoundIdx = minSizeIdx;

            TrieNode *curr = root;

            for (char &ch : search)
            {
                if (curr->children[ch - 'a'] != NULL)
                {
                    if (curr->isEnd)
                    {
                        currFoundIdx = curr->idxInContainer;
                    }
                    curr = curr->children[ch - 'a'];
                }
                else
                {
                    break;
                }
            }

            result.push_back(currFoundIdx);
        }

        return result;
    }
};

int main()
{

    return 0;
}