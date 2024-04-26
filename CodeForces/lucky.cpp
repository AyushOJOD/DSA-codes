#include <bits/stdc++.h>
using namespace std;

bool is_lucky_ticket(string &ticket)
{

    if (ticket.length() != 6)
        return false;

    int first_half = stoi(ticket.substr(0, 3));
    int second_half = stoi(ticket.substr(3, 3));

    int sum_first_half = 0, sum_second_half = 0;
    while (first_half > 0)
    {
        sum_first_half += first_half % 10;
        first_half /= 10;
    }
    while (second_half > 0)
    {
        sum_second_half += second_half % 10;
        second_half /= 10;
    }

    return sum_first_half == sum_second_half;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string ticket;
        cin >> ticket;
        cout << (is_lucky_ticket(ticket) ? "YES" : "NO") << endl;
    }

    return 0;
}