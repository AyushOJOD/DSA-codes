#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x)
    {
        val = x;
        next = NULL;
    }
};

void reorderList(Node *head)
{
    if (!head || !head->next || head->next->next)
        return;

    Node *penultimate = head;

    while (penultimate->next->next)
    {
        penultimate = penultimate->next;
    }

    penultimate->next->next = head->next;
    head->next = penultimate->next;

    penultimate->next = NULL;

    reorderList(head->next->next);
}

int main()
{

    return 0;
}