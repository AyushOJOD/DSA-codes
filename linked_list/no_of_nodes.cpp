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

int getCount(node *head)
{
    int pos = 0;
    node *curr = head;
    while (curr)
    {
        pos++;
        curr = curr->next;
    }

    return pos;
}

int main()
{

    node *head = new node(10);
    node *temp1 = new node(20);
    node *temp2 = new node(30);
    node *temp3 = new node(40);
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;

    cout << getCount(head) << endl;

    return 0;
}