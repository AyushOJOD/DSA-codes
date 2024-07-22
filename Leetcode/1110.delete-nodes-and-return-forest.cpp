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
    void solve(TreeNode *node, unordered_set<int> &del, bool is_root, vector<TreeNode *> ans)
    {
        if (!root)
        {
            return;
        }

        if (del.find(node) != del.end())
        {
            solve(node->left, del, true, ans);
            solve(node->right, del, true, ans);
        }
        else
        {
            if (is_root)
            {
                ans.push_back(node);
            }

            TreeNode *leftNode = node->left;
            TreeNode *rightNode = node->right;

            if (node->left)
            {
                if (del.find(node->left) != del.end())
                {
                    node->left = NULL;
                }
            }
            if (node->right)
            {
                if (del.find(node->right) != del.end())
                {
                    node->right = NULL;
                }
            }
            solve(node->left, del, false, ans);
            solve(node->right, del, false, ans);
        }
    }

public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        unordered_set<int> del(to_delete.begin(), to_delete.end());

        vector<TreeNode *> ans;

        solve(node, del, true, ans);

        return ans;
    }
};

int main()
{

    return 0;
}