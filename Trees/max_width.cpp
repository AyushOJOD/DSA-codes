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

int width(TreeNode *root)
{
    if (root == NULL)
        return 0;

    queue<TreeNode> q = new LinkedList<Node>();
    q.push(root);

    int res = 0;

    while (!q.empty())
    {
        int count = q.size();
        int res = max(res, count);

        TreeNode *curr = q.front();
        q.pop();

        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
    return res;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->left->left->left = new TreeNode(10);
    root->left->left->left->right = new TreeNode(11);
    root->left->left->left->left->left = new TreeNode(12);

    cout << width(root) << endl;

    return 0;
}