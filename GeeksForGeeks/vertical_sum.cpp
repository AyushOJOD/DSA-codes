#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    vector<int> verticalSum(Node *root)
    {
        map<int, int> colMap; //{col, sum};

        queue<pair<Node *, int>> q; //{node, col}
        q.push({root, 0});

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            Node *node = curr.first;
            int col = curr.second;

            colMap[col] += node->data;

            if (node->left)
            {
                q.push({node->left, col - 1});
            }
            if (node->right)
            {
                q.push({node->right, col + 1});
            }
        }

        vector<int> ans;

        for (auto &it : colMap)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main()
{

    return 0;
}