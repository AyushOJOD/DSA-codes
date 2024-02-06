#include <bits/stdc++.h>
using namespace std;

// Naive approach can use a stack

void reverse(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }

    int x = q.front();
    q.pop();
    reverse(q);
    q.push(x);
}

int main()
{

    return 0;
}