#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int data;
};

class Solution
{
private:
    Node *LCA(Node *root, Node *one, Node *two)
    {
        if (!root || root == one || root == two)
        {
            return root;
        }

        Node *leftTree = LCA(root->left, one, two);
        Node *rightTree = LCA(root->right, one, two);

        if (!leftTree)
        {
            return rightTree;
        }
        else if (!rightTree)
        {
            return leftTree;
        }
        else
        {
            return root;
        }

        return NULL;
    }

public:
    int NumberOFTurns(struct Node *root, int first, int second)
    {
        Node *lca = LCA(root, first, second);
    }
};

int main()
{

    return 0;
}