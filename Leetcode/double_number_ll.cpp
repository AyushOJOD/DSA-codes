#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int twiceOfVal(ListNode *head)
{

    if (!head)
        return 0;

    int doubledValue = head->val * 2 + twiceOfVal(head->next);

    head->val = doubledValue % 10;

    return doubledValue / 10;
}

ListNode *doubleIt(ListNode *head)
{
    int carry = twiceOfVal(head);

    if (carry)
    {
        head = new ListNode(carry, head);
    }

    return head;
}

int main()
{

    return 0;
}