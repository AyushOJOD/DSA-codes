#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

void getTraversals(TreeNode *root)
{
    vector<int> inOrder, preOrder, postOrder;

    if (!root)
    {
        return;
    }

    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            preOrder.push_back(it.first->val);
            it.second++;
            st.push(it);

            if (it.first->left)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            inOrder.push_back(it.first->val);
            it.second++;
            st.push(it);

            if (it.first->right)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            postOrder.push_back(it.first->val);
            // Dont push back again
        }
    }
}

int main()
{

    return 0;
}