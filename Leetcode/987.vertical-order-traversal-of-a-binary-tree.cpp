#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodes;   // {vertical, {level, nodes}}
    queue<pair<TreeNode *, pair<int, int>>> q; // {node, {vertical, level}}
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto it = q.front();
        TreeNode *node = it.first;
        int vertical = it.second.first;
        int level = it.second.second;

        nodes[vertical][level].insert(node->val);

        if (node->left)
        {
            q.push({node->left, {vertical - 1, level + 1}});
        }
        if (node->right)
        {
            q.push({node->right, {vertical + 1, level + 1}});
        }
    }

    vector<vector<int>> ans;

    for (auto it : nodes)
    {
        vector<int> column;
        for (auto q : it.second)
        {
            column.insert(column.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(column);
    }

    return ans;
}

int main()
{

    return 0;
}
