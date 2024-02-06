#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *insertBeg(Node *head, int x)
{
    Node *temp = new Node(x);

    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }

    while (curr->next != head)
    {
        curr = curr->next;
    }

    curr->next = temp;
    temp->next = head;
    return temp;
}

Node *insertOpti(Node *head, int x)

{
    Node *temp = new Node(x);

    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }

    temp->next = head->next;
    head->next = temp;

    int t = temp->data;
    temp->data = head->data;
    head->data = t;

    return head;
}

Node *insertEnd(Node *head, int x)

{
    Node *temp = new Node(x);

    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }

    temp->next = head->next;
    head->next = temp;

    int t = temp->data;
    temp->data = head->data;
    head->data = t;

    return temp; // we return temp as new head because the elemnent before it itself becomes the lasts
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
    temp3->next = head;

    return 0;
}