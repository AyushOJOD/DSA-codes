#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *mergeTwoLists(Node *l1, Node *l2)
{
    Node *dummy = new Node(-1);
    Node *res = dummy;

    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            res->bottom = l1;
            res = l1;
            l1 = l1->bottom;
        }
        else
        {
            res->bottom = l2;
            res = l2;
            l2 = l2->bottom;
        }
        res->next = nullptr;
    }

    if (l1)
        res->bottom = l1;
    else
        res->child = l2;

    if (dummy->bottom)
    {
        dummy->bottom->next = NULL;
    }

    return dummy->bottom;
}

Node *flatten(Node *root)
{
    // Your code here
    if (!root || !root->next)
    {
        return root;
    }

    Node *newHead = flatten(root->next);
    root = merge(root, newNode);

    return root;
}

int main()
{

    return 0;
}