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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<
            pair<int, ListNode *>,
            vector<pair<int, ListNode *>>,
            greater<pair<int, ListNode *>>>
            pq;

        int n = lists.size();

        for (int i = 0; i < n; i++)
        {
            ListNode *curr = lists[i];

            while (curr)
            {
                pq.push({curr->val, curr});

                curr = curr->next;
            }
        }

        ListNode *prev = new ListNode(-1);
        ListNode *head = prev;

        while (!pq.empty())
        {
            auto el = pq.top();

            prev->next = el.second;
            prev = prev->next;

            pq.pop();
        }

        return head->next;
    }
};

int main()
{

    return 0;
}