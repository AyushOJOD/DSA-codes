#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node *nextRight;
};

class Solution
{
public:
    void connect(Node *root)
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();

                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }

                if (i != size - 1)
                {
                    Node *next = q.front();
                    curr->nextRight = next;
                }
                else
                {
                    curr->nextRight = NULL;
                }
            }
        }
    }
};

int main()
{

    return 0;
}