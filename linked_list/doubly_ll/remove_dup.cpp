#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *removeDuplicates(struct Node *head)
{
    // Your code here
    if (!head->next || !head)
    {
        return head;
    }

    Node *curr = head;

    while (curr && curr->next)
    {
        if (curr->data == curr->next->data)
        {
            Node *nxt = curr->next;
            curr->next = nxt->next;

            if (nxt->next)
            {
                nxt->next->prev = curr;
            }
            delete nxt;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

int main()
{

    return 0;
}