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
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (head && !head->next)
        {
            return head;
        }

        ListNode *prev = head;
        ListNode *curr = head->next;

        while (curr)
        {
            int gcd = __gcd(prev->val, curr->val);
            ListNode *gcdNode = new ListNode(gcd);

            prev->next = gcdNode;
            gcdNode->next = curr;

            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};

int main()
{

    return 0;
}