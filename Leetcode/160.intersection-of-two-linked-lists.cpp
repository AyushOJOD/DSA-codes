#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *curr1 = headA;
    ListNode *curr2 = headB;

    while (curr1 != curr2)
    {
        if (!curr1)
        {
            curr1 = headB;
        }
        else
        {
            curr1 = curr1->next;
        }
        if (!curr2)
        {
            curr2 = headA;
        }
        else
        {
            curr2 = curr2->next;
        }
    }

    return curr1;
}

int main()
{

    return 0;
}