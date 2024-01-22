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

bool isIdentical(Node *head1, Node *head2)
{
    Node *curr1 = head1;
    Node *curr2 = head2;

    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data != curr2->data)
            return false;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    if (curr1 == NULL && curr2 == NULL)
        return true;
    return false;
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