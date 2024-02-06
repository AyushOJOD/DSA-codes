#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int size, cap;
    int *arr;
    Queue(int c)
    {
        cap = c;
        size = 0;
        arr = new int[cap];
    }
};

void enqueue(Queue *q, int x)
{
    if (q->size == q->cap)
    {
        return;
    }
    else
    {
        q->arr[q->size] = x;
        q->size++;
    }
}

int main()
{

    return 0;
}