#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string word;
    int freq;
    Node *prev;
    Node *next;

    Node(string k) : word(k), freq(1), prev(nullptr), next(nullptr) {}
};

class AllOne
{
public:
    Node *head, *tail;
    unordered_map<string, Node *> um;

    AllOne()
    {
        head = new Node("");
        tail = new Node("");
        head->next = tail;
        tail->prev = head;
    }

    void moveToCorrectNextPosition(Node *node)
    {
        Node *ptr = node->next;
        while (ptr != tail && node->freq > ptr->freq)
        {
            ptr = ptr->next;
        }

        if (ptr != node->next)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;

            ptr->prev->next = node;
            node->prev = ptr->prev;
            node->next = ptr;
            ptr->prev = node;
        }
    }

    void moveToCorrectPrevPosition(Node *node)
    {
        Node *ptr = node->prev;
        while (ptr != head && node->freq < ptr->freq)
        {
            ptr = ptr->prev;
        }

        if (ptr != node->prev)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;

            ptr->next->prev = node;
            node->next = ptr->next;
            node->prev = ptr;
            ptr->next = node;
        }
    }

    void inc(string word)
    {
        if (um.find(word) != um.end())
        {
            Node *node = um[word];
            node->freq++;

            moveToCorrectNextPosition(node);
        }
        else
        {
            Node *node = new Node(word);
            node->next = head->next;
            node->prev = head;

            head->next->prev = node;
            head->next = node;

            um[word] = node;

            moveToCorrectNextPosition(node);
        }
    }

    void dec(string word)
    {
        Node *node = um[word];
        node->freq--;

        moveToCorrectPrevPosition(node);

        if (node->freq == 0)
        {
            node->next->prev = node->prev;
            node->prev->next = node->next;
            um.erase(word);
            delete node;
        }
    }

    string getMaxKey()
    {
        string ans = "";
        if (tail->prev != head)
            ans = tail->prev->word;
        return ans;
    }

    string getMinKey()
    {
        string ans = "";
        if (head->next != tail)
            ans = head->next->word;
        return ans;
    }
};

int main()
{

    return 0;
}