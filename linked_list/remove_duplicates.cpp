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

// Remove duplicates from unsorted linked list
Node *removeDuplicates(Node *head)
{
    Node *curr = head;
    int pos = 1;
    unordered_map<*Node, int> mp;

    while (curr != NULL)
    {
        if (mp.find(curr->data) != mp.end())
        {
        }
    }
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