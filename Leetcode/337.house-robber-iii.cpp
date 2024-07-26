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

class Solution
{
private:
    pair<int, int> helper(TreeNode *root, unordered_map<TreeNode *, pair<int, int>> &treeMap)
    {
        if (!root)
        {
            return {0, 0};
        }

        if (treeMap.find(root) != treeMap.end())
        {
            return treeMap[root];
        }

        pair<int, int> leftTree = helper(root->left, treeMap);
        pair<int, int> rightTree = helper(root->right, treeMap);

        int rob = root->val + leftTree.second + rightTree.second;
        int notRob = 0 + max(leftTree.first, leftTree.second) + max(rightTree.first, rightTree.second);

        return treeMap[root] = {rob, notRob};
    }

public:
    int rob(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        if (root && !root->left && !root->right)
        {
            return root->val;
        }

        unordered_map<TreeNode *, pair<int, int>> treeMap;

        pair<int, int> result = helper(root, treeMap);

        return max(result.first, result.second);
    }
};

int main()
{

    return 0;
}