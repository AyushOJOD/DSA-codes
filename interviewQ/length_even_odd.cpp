#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

string solve(Node *head)
{
    if (!head)
    {
        return "even";
    }

    Node *curr = head;
    int cnt = 1;

    while (curr->next)
    {
        cnt++;
        curr = curr->next;
    }

    return (cnt % 2 == 0) ? 'even' : "odd";
}

int main()
{

    return 0;
}