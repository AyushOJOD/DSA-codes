#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

bool isPalindrome(Node *head)
{
    Node *curr = head;
    Node *temp = head;
    stack<int> s;

    while (curr)
    {
        s.push(curr->data);
        curr = curr->next;
    }

    while (temp)
    {
        if (st.top != temp->data)
        {
            return false;
        }
        else
        {
            st.pop();
            temp = temp->next;
        }
    }
    return true;
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