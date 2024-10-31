#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    struct TrieNode
    {
        char digit;
        TrieNode *children[10];
    };

    TrieNode *getNode()
    {
        TrieNode *newNode = new TrieNode();

        for (int i = 0; i <= 9; i++)
        {
            newNode->children[i] = nullptr;
        }

        return newNode;
    }

    void insert(TrieNode *root, int num)
    {
        TrieNode *curr = root;
        string str = to_string(num);

        for (char ch : str)
        {
            int idx = ch - '0';
            if (!curr->children[idx])
            {
                curr->children[idx] = getNode();
            }

            curr = curr->children[idx];
        }
    }

    int search(TrieNode *root, int num)
    {
        TrieNode *curr = root;
        string str = to_string(num);

        int len = 0;

        for (char ch : str)
        {
            int idx = ch - '0';
            if (curr->children[idx])
            {
                len++;
                curr = curr->children[idx];
            }
            else
            {
                break;
            }
        }

        return len;
    }

public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {

        TrieNode *root = getNode();

        for (int x : arr1)
        {
            insert(root, x);
        }

        int res = 0;

        for (int x : arr2)
        {
            res = max(res, search(root, x));
        }

        return res;
    }
};

int main()
{

    return 0;
}