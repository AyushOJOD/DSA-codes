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

Node *deleteHead(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == head)
    {
        delete head;
        return NULL;
    }

    head->data = head->next->data;
    head->next = head->next->next;
    return head;
}

Node *deleteKth(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *temp = head;

    for (int i = 0; i < k - 2; i++)
    {
        temp = temp->next;
    }

    temp->next = temp->next->next;
    delete temp->next;
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
    temp3->next = head;

    return 0;
}