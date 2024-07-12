#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    struct TrieNode
    {
        bool isEnd;
        TrieNode *binary[2];
        int number;
    };

    TrieNode *getNode()
    {
        TrieNode *newNode = new TrieNode();

        newNode->isEnd = false;
        newNode->number = -1;

        for (int i = 0; i < 2; i++)
        {
            newNode->binary[i] = NULL;
        }
        return newNode;
    }

    void insert(TrieNode *root, int n)
    {
        TrieNode *curr = root;

        for (int i = 31; i >= 0; i--)
        {
            int idx = (n >> i) & 1;

            if (curr->binary[idx] == NULL)
            {
                curr->binary[idx] = getNode();
            }

            curr = curr->binary[idx];
        }

        curr->isEnd = true;
        curr->number = n;
    }

public:
    int findMaximumXOR(vector<int> &nums)
    {
        TrieNode *root = getNode();

        for (int &num : nums)
        {
            insert(root, num);
        }

        int maxVal = 0;

        for (int &num : nums)
        {
            TrieNode *curr = root;

            for (int i = 31; i >= 0; i--)
            {
                int idx = (num >> i) & 1;

                if (curr->binary[1 - idx] == NULL)
                {
                    curr = curr->binary[idx];
                }
                else
                {
                    curr = curr->binary[1 - idx];
                }
            }

            maxVal = max(maxVal, (curr->number ^ num));
        }

        return maxVal;
    }
};

int main()
{

    return 0;
}