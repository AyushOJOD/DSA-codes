#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNodes(ListNode *head)
{
    if (!head)
        return NULL;

    ListNode *curr = head;
    ListNode *nxtGrtr = removeNodes(head->next);

    node->next = nxtGrtr;

    if (!nxtGrtr || nxtGrtr->val <= curr->val)
    {
        return curr;
    }

    return nxtGrtr;
}

int main()
{

    return 0;
}