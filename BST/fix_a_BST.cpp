#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void fixBST(TreeNode *root)
{
    vector<int> inorder;

    stack<TreeNode *> s;
    TreeNode *curr = root;

    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        inorder.push_back(curr->data);
        curr = curr->right;
    }

    int prev = INT_MIN;
    int first = -1, second = -1;

    for (int i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] < prev)
        {
            if (first == -1)
            {
                first = prev;
            }
            second = inorder[i];
        }
        prev = inorder[i];
    }

    cout << first << " " << second << endl;
}

int main()
{

    return 0;
}