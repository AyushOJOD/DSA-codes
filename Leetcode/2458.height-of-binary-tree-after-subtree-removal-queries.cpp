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

class Solution
{
public:
    unordered_map<int, int> heightMap;

    int getheight(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int leftHeight = getheight(root->left);
        int rightHeight = getheight(root->right);

        int height = 1 + max(leftHeight, rightHeight);
        heightMap[root->val] = height;
        return height;
    }

    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        vector<int> ans;

        getheight(root);

        for (int query : queries)
        {
            ans.push_back(heightMap[query] - 1);
        }

        return ans;
    }
};

int main()
{

    return 0;
}