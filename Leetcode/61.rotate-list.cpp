#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

ListNode *rotateRight(ListNode *head, int k)
{

    if (!head || k == 0 || !head->next)
    {
        return head;
    }

    ListNode *curr = head;
    int len = 1;

    while (curr->next)
    {
        curr = curr->next;
        len++;
    }

    curr->next = head;

    k = k % len;
    int newLen = len - k;
    curr = head;

    for (int i = 0; i < newLen - 1; i++)
    {
        curr = curr->next;
    }

    head = curr->next;
    curr->next = NULL;
    return head;
}

int main()
{

    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    Node *temp3 = new Node(40);
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;

    return 0;
}