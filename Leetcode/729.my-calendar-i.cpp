#include <bits/stdc++.h>
using namespace std;

class MyCalendar
{
public:
    vector<pair<int, int>> books;

    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        for (auto &book : books)
        {
            if (max(book.first, start) < min(book.second, end))
            {
                return false;
            }
        }
        books.push_back({start, end});
        return true;
    }
};

int main()
{

    return 0;
}