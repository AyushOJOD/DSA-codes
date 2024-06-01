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

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

Node *addOne(Node *head)
{
    // Your Code here
    // return head of list after adding one

    Node *newHead = reverse(head);

    Node *one = new Node(1);

    Node *dummy = new Node(-1);
    ListNode *curr = dummy;

    Node *t1 = newHead;
    Node *t2 = one;
    int carry = 0;

    while (t1 || t2)
    {
        int sum = 0;
        sum += carry;
        if (t1)
        {
            sum += t1->data;
        }
        if (t2)
        {
            sum += t2->data;
        }

        Node *nNode = new Node(sum % 10);
        carry = sum / 10;

        curr->next = nNode;
        curr = curr->next;

        if (t1)
        {
            t1 = t1->next;
        }
        if (t2)
        {
            t2 = t2->next;
        }

        if (carry)
        {
            Node *carryVal = new Node(carry);
            curr->next = carryVal;
        }
    }

    return reverse(dummy->next);
}

int main()
{

    return 0;
}