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

bool findPath(TreeNode *root, vector<TreeNode *> &path, int n)
{
    if (root == NULL)
        return false;

    path.push_back(root);

    if (root->val == n)
        return true;

    if ((root->left && findPath(root->left, path, n)) || (root->rightv && findPath(root->right, path, n)))
        return true;

    path.pop_back();

    return false;
}

TreeNode *LCA(TreeNode *root, int n1, int n2)
{
    vector<TreeNode *> path1, path2;

    if (!findPath(root, path1, n1) && !findPath(root, path2, n2))
        return NULL;

    for (int i = 0; i < path1.size() && i < path2.size(); i++)
    {
        if (path1[i + 1] != path2[i + 1])
            return path1[i];
    }

    return NULL;
}

int main()
{

    return 0;
}