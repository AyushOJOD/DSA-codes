#include <bits/stdc++.h>
using namespace std;

// struct of Trie

struct TrieNode
{
    bool wordEnd;
    string word;
    TrieNode *children[26];
};

// get a new Node
TrieNode *getNode()
{
    TrieNode *newNode = new TrieNode();

    // set the constraints
    newNode->wordEnd = false;
    newNode->word = "";

    for (int i = 0; i < 26; i++)
    {
        newNode->children[i] = NULL;
    }

    return newNode;
}

// Insertion
void insert(TrieNode *root, string &word)
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

    curr->wordEnd = true;
    curr->word = word;
}

// Searching
bool search(TrieNode *root, string &word)
{
    TrieNode *curr = root;

    for (char &ch : word)
    {
        int idx = ch - 'a';

        if (curr->children[idx] == NULL)
        {
            return false;
        }

        curr = curr->children[idx];
    }

    return curr->wordEnd;
}

bool startsWith(TrieNode *root, string &word)
{
    TrieNode *curr = node;

    for (char &ch : word)
    {
        int idx = ch - 'a';

        if (curr->children[idx] == NULL)
        {
            return false;
        }

        curr = curr->children[idx];
    }

    return true;
}

int main()
{

    return 0;
}