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

void lineByLineBFS(TreeNode *root)
{

    if (root == NULL)
    {
        return;
    }

    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.size() > 1)
    {
        TreeNode *node = q.front();
        q.pop();
        if (node == NULL)
        {
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << node->val << " ";
        if (node->left != NULL)
        {
            q.push(node->left);
        }
        if (node->right != NULL)
        {
            q.push(node->right);
        }
    }
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

    lineByLineBFS(root);

    return 0;
}