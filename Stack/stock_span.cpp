#include <bits/stdc++.h>
using namespace std;

void stock(int arr[], int n)
{
    stack<int> s;
    s.push(0);
    cout << 1 << " ";

    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] <= arr[i])
        {
            s.pop();
        }
        int span = s.empty() ? i + 1 : i - s.top(); // This is the main logic
        cout << span << " ";
        s.push(i);
    }
}

int main()
{

    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    stock(arr, n);

    return 0;
}
