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

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        Node *front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    return prev;
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

    cout << reverse(head)->data << endl;

    return 0;
}