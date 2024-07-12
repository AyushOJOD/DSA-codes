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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *originalHead = head;

        int sum = 0;
        while (curr)
        {
            if (curr->val == 0)
            {
                head->val = sum;
                sum = 0;
                if (curr->next != NULL)
                {
                    head = head->next;
                }
            }

            sum += curr->val;
            curr = curr->next;
        }
        head->next = nullptr;
        return originalHead;
    }
};

int main()
{

    return 0;
}