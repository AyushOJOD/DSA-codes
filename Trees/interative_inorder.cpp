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

void Inorder(Node *root)
{
    stack<TreeNode *> st;

    TreeNode *curr = root;
    while (curr != NULL || !st.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();

        cout << curr->val << " ";
        curr = curr->right;
    }
}

int main()
{

    return 0;
}