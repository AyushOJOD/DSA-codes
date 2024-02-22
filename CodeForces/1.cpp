#include <bits/stdc++.h>

using namespace std;

vector<int> vec(1e6 + 1, 0);

void solve()
{

    int n;

    n = 1e6;

    long long solution = 0;

    for (int cntr = 0; cntr < n; cntr++)
    {
        int num = cntr;
        // cin>>num;

        int sum = 0;
        while (num > 0)
        {
            // cout<<num<<endl;
            sum = sum + (num % 10);

            num = num / 10;
        }

        solution += sum;

        vec[cntr] = solution;
    }

    // cout << solution << endl;

    return;
}

int main()
{
    long long tst;

    cin >> tst;

    solve();

    while (tst--)
    {
        int num;

        cin >> num;

        cout << vec[num] << endl;
    }

    return 0;
}