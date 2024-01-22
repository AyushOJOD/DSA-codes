#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next; // Self refrential structures
    node(int x);
    {
        data = x;
        next = NULL;
    }
};

int newWay()
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
}

int main()
{
    node *head = new node(10);
    node *temp1 = new node(20);
    node *temp2 = new node(30);
    head->next = temp1;
    temp1->next = temp2;

    return 0;
}