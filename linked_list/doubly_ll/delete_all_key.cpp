#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

void deleteAllOccurOfX(struct Node **head_ref, int x)
{
    // Write your code here
    Node *curr = head_ref;

    while (curr)
    {
        if (curr->data == x)
        {
            if (curr == head_ref)
            {
                head = curr->next;
            }

            Node *nxtNode = curr->next;
            Node *prevNode = curr->prev;

            if (nxtNode)
                nxtNode->prev = prevNode;
            if (prevNode)
                prevNode->next = nxtNode;
            delete curr;
            curr = nxtNode;
        }
        else
        {
            curr = curr->next;
        }
    }
}

int main()
{

    return 0;
}