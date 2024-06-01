#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr){} * ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *curr = dummy;

    ListNode *t1 = l1;
    ListNode *t2 = l2;
    int carry = 0;

    while (t1 || t2)
    {
        int sum = 0;
        sum += carry;
        if (t1)
        {
            sum += t1->val;
        }
        if (t2)
        {
            sum += t2->val;
        }

        ListNode *nNode = new ListNode(sum % 10);
        carry = sum / 10;
        curr->next = nNode;
        curr = curr->next;

        if (t1)
            t1 = t1->next;
        if (t2)
            t2 = t2->next;
    }

    if (carry)
    {
        ListNode *carryNode = new ListNode(carry);
        curr->next = carryNode;
    }

    return dummy->next;
}

int main()
{

    return 0;
}