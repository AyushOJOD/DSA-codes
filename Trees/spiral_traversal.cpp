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

// The idea is to take a boolean variable to keep track of the direction of the spiral traversal say reverse.
// We use a queue to print normal data and a stack to print reverse data.

void spiral(TreeNode *root)
{
    if (root == NULL)
        return;

    queue<TreeNode *> q;
    stack<int> s;
    bool reverse = false;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            TreeNode *curr = q.front();
            q.pop();

            if (reverse)
            {
                s.push(curr->val);
            }
            else
            {
                cout << curr->val << " ";
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }

        if (reverse)
        {
            while (!s.empty())
            {
                cout << s.top() << " ";
                s.pop();
            }
        }

        reverse = !reverse;
        cout << endl;
    }
}

void spiralOptiised(TreeNode *root)

{
    if (root == NULL)
        return;
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;

    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            TreeNode *curr = s1.top();
            s1.pop();

            cout << curr->val << " ";
            if (curr->left)
                s2.push(curr->left);
            if (curr->right)
                s2.push(curr->right);
        }

        while (!s2.empty())
        {
            TreeNode *curr = s2.top();
            s2.pop();

            cout << curr->val << " ";
            if (curr->left)
                s1.push(curr->left);
            if (curr->right)
                s1.push(curr->right);
        }
    }
}

int main()
{

    return 0;
}
