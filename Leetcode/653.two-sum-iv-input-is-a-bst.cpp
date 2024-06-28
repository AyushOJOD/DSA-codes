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
public:
    bool findTarget(TreeNode *root, int k)
    {
        unordered_set<int> st;

        queue<TreeNode *> q;
        q.push(root);
        st.insert(k - root->val);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (st.find(k - curr->val) != st.end())
            {
                return true;
            }

            st.insert(curr->val);

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}