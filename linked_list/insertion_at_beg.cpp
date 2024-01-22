#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

node *insertion(node *head, int x)
{
    node *temp = new node(x);
    temp->next = head;
    return temp;
}

void printList(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{

    node *head = NULL;
    head = insertion(head, 10);
    head = insertion(head, 20);
    head = insertion(head, 30);
    head = insertion(head, 40);
    printList(head);

    return 0;
}
