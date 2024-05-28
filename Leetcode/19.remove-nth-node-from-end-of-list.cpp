#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr){} * ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (!head->next && n == 1)
    {
        return nullptr;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    int idx = 0;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    if (fast == NULL)
    {
        return head->next;
    }

    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode *delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;

    return head;
}

int main()
{

    return 0;
}