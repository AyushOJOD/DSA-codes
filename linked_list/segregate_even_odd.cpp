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

Node *separateEvenOdd(Node *head)
{
}

int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(30);
    Node *temp2 = new Node(20);
    Node *temp3 = new Node(50);
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;

    return 0;
}