#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    Node *targetNode;

    void getParent(Node *root, unordered_map<Node *, Node *> &parent, int target)
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();

            if (node->data == target)
            {
                targetNode = node;
            }

            if (node->right)
            {
                parent[node->right] = node;
                q.push(node->right);
            }
            if (node->left)
            {
                parent[node->left] = node;
                q.push(node->left);
            }
        }
    }

    int minTime(Node *root, int target)
    {
        unordered_map<Node *, Node *> parent;
        parent[root] = nullptr;
        getParent(root, parent, target);

        queue<pair<Node *, int>> q;
        unordered_set<Node *> vis;

        int maxTime = 0;

        q.push({targetNode, 0});
        vis.insert(targetNode);

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            Node *curr = it.first;
            int time = it.second;

            maxTime = max(maxTime, time);

            if (curr->left && vis.find(curr->left) == vis.end())
            {
                q.push({curr->left, time + 1});
                vis.insert(curr->left);
            }
            if (curr->right && vis.find(curr->right) == vis.end())
            {
                q.push({curr->right, time + 1});
                vis.insert(curr->right);
            }
            if (parent.find(curr) != parent.end() && parent[curr] != nullptr && vis.find(parent[curr]) == vis.end())
            {
                q.push({parent[curr], time + 1});
                vis.insert(parent[curr]);
            }
        }

        return maxTime;
    }
};

int main()
{

    return 0;
}