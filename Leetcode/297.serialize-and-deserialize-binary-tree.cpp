#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    string stringFormat = "";

    if (!root)
    {
        return stringFormat;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            stringFormat.append("$,");
        }
        else
        {
            stringFormat.append((curr->val) + ",");
        }

        if (curr)
        {
            q.push(curr->left);
            q.push(curr->right);
        }
    }

    return stringFormat;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if (!data.length())
    {
        return NULL;
    }

    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == '$')
        {
            node->left = NULL;
        }
        else
        {
            TreeNode *leftNode = new TreeNode(stio(str));
            node->left = leftNode;
        }

        getline(s, str, ',');
        if (str == '$')
        {
            node->right = NULL;
        }
        else
        {
            TreeNode *rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
        }
    }

    return root;
}

int main()
{

    return 0;
}