#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr){} * ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteMiddle(ListNode *head)
{
    if (!head)
    {
        return nullptr;
    }

    ListNode *prev = ListNode(0);
    prev->next = head;

    ListNode *slow = prev;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;

    return prev->next;
}

int main()
{

    return 0;
}