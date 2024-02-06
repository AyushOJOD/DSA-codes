#include <bits/stdc++.h>
using namespace std;

struct TwoStacks
{
    int *arr, cap, top1, top2;
    TwoStacks(int n)
    {
        cap = n;
        arr = new int[n];
        top1 = -1;
        top2 = cap;
    }

    void push1(int x)
    {
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = x;
        }
        else
        {
            cout << "Stack Overflow" << endl;
            exit(1);
        }
    }

    void push2(int x)
    {
        if (top1 < top2 - 1)
        {
            top2--;
            arr[top2] = x;
        }
        else
        {
            cout << "Stack Overflow" << endl;
            exit(1);
        }
    }

    void pop1()
    {
        if (top1 >= 0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        else
        {
            cout << "Stack Underflow" << endl;
            exit(1);
        }
    }

    void pop2()
    {
        if (top2 < cap)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        else
        {
            cout << "Stack Underflow" << endl;
            exit(1);
        }
    }
}

int
main()
{

    return 0;
}