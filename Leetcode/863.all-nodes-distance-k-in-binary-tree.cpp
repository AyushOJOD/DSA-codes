#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    vector<int> ans;

    if (!root)
    {
        return ans;
    }

    map<TreeNode *, TreeNode *> parent; // {node->parent}
    queue<TreeNode *> traverse;

    traverse.push(root);
    parent[root] = -1;

    while (!traverse.empty())
    {
        TreeNode *node = traverse.front();
        q.pop();

        if (node->left)
        {
            traverse.push(node->left);
            parent[node->left] = node;
        }

        if (node->right)
        {
            traverse.push(node->right);
            parent[node->right] = node;
        }
    }

    unordered_map<TreeNode *, bool> vis;
    queue<TreeNode *> q;
    q.push(target);
    vis[target] = true;
    int curr_lvl = 0;

    while (!q.empty())
    {
        int size = q.size();
        if (curr_lvl++ == k)
        {
            break;
        }
        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left && !vis[curr->left])
            {
                q.push(curr->left);
                vis[curr->left] = true;
            }
            if (curr->right && !vis[curr->right])
            {
                q.push(curr->right);
                vis[curr->right] = true;
            }
            if (parent[curr] && !vis[parent[curr]])
            {
                q.push(parent[curr]);
                vis[parent[curr]] = true;
            }
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        ans.push_back(q.front()->val);
        q.pop();
    }

    return ans;
}

int main()
{

    return 0;
}