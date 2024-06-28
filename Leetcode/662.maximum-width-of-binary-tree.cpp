#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    map<int, int> isPresent;                   //{level, if it is present}
    queue<pair<TreeNode *, pair<int, int>>> q; // {node, {vertical, level}}

    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto it = q.front();
        TreeNode *node = it.first;
        int vertical = it.second.second;
        int level = it.second.first;
        q.pop();

        if (isPresent.find(vertical) == isPresent.end())
        {
            isPresent[vertical] = 1;
        }

        if (node->left)
        {
            q.push({node->left, {level + 1, vertical - 1}});
        }
        if (node->right)
        {
            q.push({node->right, {level + 1, vertical + 1}});
        }
    }

    int maxVal = 0, minVal = 0;

    for (auto it : isPresent)
    {
        if (it.first > maxVal)
        {
            maxVal = it.first;
        }
        if (it.first < minVal)
        {
            minVal = it.first;
        }
    }

    return maxVal + abs(minVal) + 1;
}

int main()
{

    return 0;
}
