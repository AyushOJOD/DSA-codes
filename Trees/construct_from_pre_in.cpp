#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// We can't construct a tree from only preOrder and postOrder traversal

TreeNode *cTree(vector<int> &preOrder, vector<int> inOrder, int is, int ie)
{
    int preIndex = 0;

    if (is > ie)
        return NULL;

    TreeNode *root = new TreeNode(preOrder[preIndex++]);

    int inIndex;

    for (int i = is; i <= ie; i++)
    {
        if (inOrder[i] == root->val)
        {
            inIndex = i;
            break;
        }
    }

    root->left = cTree(preOrder, inOrder, is, inIndex - 1);
    root->right = cTree(preOrder, inOrder, inIndex + 1, ie);

    return root;
}

int main()
{

    return 0;
}