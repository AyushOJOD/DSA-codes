#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }

        ListNode *mid = findMiddle(head);

        TreeNode *root = new TreeNode(mid->val);

        if (head == mid)
        {
            return root;
        }

        root->left = sortedListToBST(head);

        root->right = sortedListToBST(mid->next);

        return root;
    }

private:
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *prevPtr = nullptr;
        ListNode *slowPtr = head;
        ListNode *fastPtr = head;

        while (fastPtr && fastPtr->next)
        {
            prevPtr = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        if (prevPtr)
        {
            prevPtr->next = nullptr;
        }

        return slowPtr;
    }
};

int main()
{

    return 0;
}