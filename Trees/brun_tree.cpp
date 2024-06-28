#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        val = val;
        left = right = NULL;
    }
};

int minTime(TreeNode *root, int start)
{
    // Your code goes here
    unordered_map<TreeNode *, TreeNode *> parent; // {node->parent}

    queue<TreeNode *> q;
    q.push(root);
    parent[root] = NULL;
    TreeNode *burnedNode = NULL;

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->val == start)
            {
                burnedNode = curr;
            }

            if (curr->left)
            {
                q.push(curr->left);
                parent[curr->left] = curr;
            }

            if (curr->right)
            {
                q.push(curr->right);
                parent[curr->right] = curr;
            }
        }
    }

    cout << burnedNode->val << endl;

    int time = 0;

    queue<TreeNode *> burnQueue;
    unordered_map<TreeNode *, bool> vis;

    burnQueue.push(burnedNode);
    vis[burnedNode] = true;

    while (!burnQueue.empty())
    {
        int size = burnQueue.size();
        bool anyBurned = false;
        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = burnQueue.front();
            burnQueue.pop();

            if (curr->left && !vis[curr->left])
            {
                vis[curr->left] = true;
                burnQueue.push(curr->left);
                anyBurned = true;
            }
            if (curr->right && !vis[curr->right])
            {
                vis[curr->right] = true;
                burnQueue.push(curr->right);
                anyBurned = true;
            }
            if (parent[curr] && vis[parent[curr]])
            {
                vis[parent[curr]] = true;
                burnQueue.push(parent[curr]);
                anyBurned = true;
            }
        }
        if (anyBurned)
        {
            time++;
        }
    }

    return time;
}

int main()
{
    int n

        return 0;
}