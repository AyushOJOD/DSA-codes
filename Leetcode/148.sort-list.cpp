#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr){} * Node(int x) : val(x), next(nullptr){} * Node(int x, Node *next) : val(x), next(next) {}
};

Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return right;
    }

    Node *ans = new Node(-1);
    Node *temp = ans;

    while (left && right)
    {
        if (left->val < right->val)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    return ans->next;
}

Node *sortList(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    Node *mid = findMid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL; // To break the nodes

    left = sortList(left);
    right = sortList(right);

    Node *res = merge(left, right);

    return res;
}

int main()
{

    return 0;
}