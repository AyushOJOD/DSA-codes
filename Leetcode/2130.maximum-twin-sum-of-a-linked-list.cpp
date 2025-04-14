#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        stack<int> st;
        ListNode *slow = head;
        ListNode *fast = head;

        // Move slow to the midpoint and store first half in stack
        while (fast && fast->next)
        {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        int maxVal = 0;

        // Now slow is at the beginning of the second half
        while (slow)
        {
            int first = st.top();
            st.pop();
            int second = slow->val;
            maxVal = max(maxVal, first + second);
            slow = slow->next;
        }

        return maxVal;
    }
};

int main()
{

    return 0;
}