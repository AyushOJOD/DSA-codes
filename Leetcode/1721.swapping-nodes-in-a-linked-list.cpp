#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *first = NULL, *second = NULL;

        ListNode *curr = head;

        while (k != 1)
        {
            curr = curr->next;
            k--;
        }

        first = curr;

        ListNode *temp = head;

        while (curr->next != NULL)
        {
            temp = temp->next;
        }

        second = temp;

        swap(first->val, second->val);

        return head;
    }
};

int main()
{

    return 0;
}