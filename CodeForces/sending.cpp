#include <iostream>
#include <vector>

using namespace std;

string can_send_messages(int n, int f, int a, int b, vector<int> &moments)
{
    int no_off_time = f / a;

    if (moments[n - 1] <= no_off_time)
    {
        return "YES";
    }
    f = f - moments[0];

    for (int i = 0; i < n; i++)
    {
        if (moments[i + 1] - moments[i] > b)
        {
            f = f - a;
        }
        else
        {
            f = f - (moments[i + 1] - moments[i]);
        }
    }

    if (f >= 0)
    {
        return "YES";
    }

    return "NO";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, f, a, b;
        cin >> n >> f >> a >> b;

        vector<int> moments(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> moments[i];
        }

        cout << can_send_messages(n, f, a, b, moments) << endl;
    }

    return 0;
}
