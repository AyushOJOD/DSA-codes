#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
private:
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = new Node(-1);

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    Node *addOneUtil(Node *head)
    {
        Node *curr = head;
        Node *temp;

        int carry = 1, sum = 0;

        while (curr)
        {
            sum = carry + curr->data;

            carry = (sum >= 10) ? 1 : 0;

            sum = sum % 10;

            curr->data = sum;

            temp = curr->next;
            curr = curr->next;
        }

        if (carry > 0)
        {
            temp->next = new Node(carry);
        }

        return head;
    }

public:
    Node *addOne(Node *head)
    {
        // Your Code here
        head = reverse(head);

        head = addOneUtil(head);

        head = reverse(head);

        return head;
    }
};

int main()
{

    return 0;
}