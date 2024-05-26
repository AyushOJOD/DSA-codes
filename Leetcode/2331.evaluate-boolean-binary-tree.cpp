#include <bits/stdc++.h>
using namespace std;

bool evaluateTree(TreeNode *root)
{

    if (!root->left)
    {
        return root->val == 1;
    }

    int A = evaluateTree(root->left);
    int B = evaluateTree(root->right);

    if (root->val == 2)
    { // OR
        return A or B;
    }
    else
    {
        return A and B;
    }

    return root->val;
}

int main()
{

    return 0;
}