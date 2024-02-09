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

void BFS(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode> q = new LinkedList<TreeNode>();
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
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

    return 0;
}