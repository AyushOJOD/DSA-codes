#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *segregate(Node *head)
{

    if (!head || !head->next)
    {
        return head;
    }

    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);
    Node *zeroHead = new Node(-1);

    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;

    Node *curr = head;

    while (curr)
    {
        if (curr->data == 0)
        {
            zero->next = curr;
            zero = zero->next;
        }
        else if (curr->data == 1)
        {
            one->next = curr;
            one = one->next;
        }
        else
        {
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }

    zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
    one->next = twoHead->next;
    two->next = NULL;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return oneHead->next;
}

int main()
{

    return 0;
}