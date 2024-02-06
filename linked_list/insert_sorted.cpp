#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *insertSorted(Node *head, int x)
{
    Node *temp = new Node(x);
    Node *curr = head;

    if (head == NULL)
    {
        return temp;
    }
    while (curr->next && curr->next->data < x)
    {
        curr = curr->next;
    }

    temp->next = curr->next;
    cur->next = temp;

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