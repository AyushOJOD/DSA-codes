#include <bits/stdc++.h>
using namespace std;

struct meetings
{
    int start;
    int end;
    int idx;
};

class Solution
{
private:
    bool static comp(meetings m1, meetings m2)
    {
        return m1.end < m2.end;
    }

public:
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<meetings> meet(n);

        for (int i = 0; i < n; i++)
        {
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].idx = i + 1;
        }

        sort(meet.begin(), meet.end(), comp);

        int freeTime = meet[0].end;
        int cnt = 1;

        for (int i = 1; i < n; i++)
        {
            int startTime = meet[i].start;
            int endTime = meet[i].end;
            int idx = meet[i].idx;

            if (startTime >= freeTime)
            {
                freeTime = endTime;
                cnt++;
            }
        }

        return cnt;
    }
}

int
main()
{

    return 0;
}