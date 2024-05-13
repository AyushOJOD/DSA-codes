#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode *node)
{
    ListNode *curr = node;

    int temp = curr->val;
    int nxtTmp = curr->next->val;

    curr->val = nxtTmp;
    curr->next->val = temp;

    curr->next = curr->next->next;
}

int main()
{

    return 0;
}