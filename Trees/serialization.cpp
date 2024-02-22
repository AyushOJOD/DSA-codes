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

void serialization(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
    {
        v.push_back(-1);
        return;
    }
    v.push_back(root->data);
    serialization(root->left, v);
    serialization(root->right, v);
}

TreeNode *deserialization(vector<int> &v)
{
    int index = 0;

    if (index == v.size())
        return NULL;

    int val = v[index];
    index++;
    if (val == -1)
        return NULL;

    TreeNode *root = new TreeNode(val);

    root->left = deserialization(v);
    root->right = deserialization(v);

    return root;
}

int main()
{

    return 0;
}