#include <bits/stdc++.h>
using namespace std;

class MyStack
{
public:
    queue<int> q1, q2;
    int underWork = 1;

    MyStack()
    {
    }

    void push(int x)
    {
        if (underWork == 1)
        {
            q1.push(x);
        }
        else
        {
            q2.push(x);
        }
    }

    int pop()
    {
        if (underWork == 1)
        {
            while (q1.size() != 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            underWork = 2;
            int value = q1.front();
            q1.pop();
            return value;
        }
        else
        {
            while (q2.size() != 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            underWork = 1;
            int value = q2.front();
            q2.pop();
            return value;
        }
        return -1;
    }

    int top()
    {
        if (underWork == 1)
        {
            while (q1.size() != 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            underWork = 2;
            int topVal = q1.front();
            q2.push(topVal);
            q1.pop();
            return topVal;
        }
        else
        {
            while (q2.size() != 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            underWork = 1;
            int topVal = q2.front();
            q1.push(topVal);
            q2.pop();
            return topVal;
        }
        return -1;
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};

int main()
{

    return 0;
}