#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

    // Check if the key is present in this node
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    // put the character in the node
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    // get to the next pointer node
    Node *getNode(char ch)
    {
        return links[ch - 'a'];
    }

    // set the node as end
    void setEnd()
    {
        flag = true;
    }

    // Check if the node is the last node
    bool isEnd()
    {
        return flag;
    }
}

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->getNode(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->getNode(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;

        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->getNode(word[i]);
        }
        return true;
    }
};

int main()
{

    return 0;
}