#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr){} * ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *oddEvenList(ListNode *head)
{

    if (!head || !head->next || !head->next->next)
        return head;

    ListNode *first = head;
    ListNode *second = head->next;
    ListNode *secStart = head->next;

    while (first->next && second->next)
    {
        first->next = second->next;
        first = first->next;
        second->next = first->next->next;
        second = second->next;
    }
    first->next = secStart;

    return head;
}

int main()
{

    return 0;
}