#include <bits/stdc++.h>
using namespace std;

// Make n number only using 5 and 6

vector<string> make_numbers(int n)
{
    queue<string> q;
    vector<string> ans;

    q.push("5");
    q.push("6");

    for (int i = 0; i < n; i++)
    {
        string curr = q.front();
        cout << curr << endl;
        q.pop();
        q.push(curr + "5");
        q.push(curr + "6");
    }
}

int main()
{

    return 0;
}