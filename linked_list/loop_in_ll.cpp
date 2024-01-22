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

int countNodes(node *head)
{
    node *curr = head;
    int count = 1;
    unordered_map<node *, int> mp;
    while (curr)
    {
        if (mp.find(curr) != mp.end())
        {
            return count - mp[curr];
        }
        mp[curr] = count;
        count++;
        curr = curr->next;
    }
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

    return 0;
}