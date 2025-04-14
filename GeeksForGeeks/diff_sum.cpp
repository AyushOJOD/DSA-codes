#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    int differenceSum(Node *root1, Node *root2)
    {
        if (!root1 && !root2)
        {
            return 0;
        }

        int sum = 0;
        queue<pair<Node *, Node *>> q;
        q.push({root1, root2});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            Node *node1 = it.first;
            Node *node2 = it.second;

            int val1 = (node1 != nullptr) ? node1->data : 0;
            int val2 = (node2 != nullptr) ? node2->data : 0;
            sum += abs(val1 - val2);

            if ((node1 && node1->left) || (node2 && node2->left))
            {
                q.push({(node1 && node1->left) ? node1->left : nullptr, (node2 && node2->left) ? node2->left : nullptr});
            }

            if ((node1 && node1->right) || (node2 && node2->right))
            {
                q.push({(node1 && node1->right) ? node1->right : nullptr, (node2 && node2->right) ? node2->right : nullptr});
            }
        }

        return sum;
    }
};

int main()
{

    return 0;
}