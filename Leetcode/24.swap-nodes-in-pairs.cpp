
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    *int val;
    *ListNode *next;
    *ListNode() : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr){} * ListNode(int x, ListNode *next) : val(x), next(next){}
                                                                                                                                      *
};

ListNode *swapPairs(ListNode *head)
{
    ListNode *curr = head;

    while (curr != NULL && curr->next != NULL)
    {
        swap(curr->val, curr->next->val);
        curr = curr->next->next;
    }

    return head->next;
}

int main()
{

    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    Node *temp3 = new Node(40);
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;

    return 0;
}
