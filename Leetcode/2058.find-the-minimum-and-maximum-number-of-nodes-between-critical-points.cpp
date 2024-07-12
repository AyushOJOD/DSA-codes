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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        ListNode *prev = head;
        ListNode *curr = head->next;

        vector<int> critical;
        int idx = 1;

        while (curr->next)
        {
            if (prev->val > curr->val && curr->val < curr->next->val)
            {
                critical.push_back(idx);
            }
            else if (prev->val < curr->val && curr->val > curr->next->val)
            {
                critical.push_back(idx);
            }

            prev = curr;
            curr = curr->next;
            idx++;
        }

        if (critical.size() < 2)
        {
            return {-1, -1};
        }

        int maxDiff = critical[critical.size() - 1] - critical[0];

        int minDiff = INT_MAX;

        for (int i = 0; i < critical.size() - 1; i++)
        {
            minDiff = min(minDiff, critical[i + 1] - critical[i]);
        }

        return {minDiff, maxDiff};
    }
};

int main()
{

    return 0;
}