#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    static bool comp(vector<int> v1, vector<int> v2)
    {
        return v1[1] < v2[1];
    }

public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        int n = courses.size();

        sort(courses.begin(), courses.end(), comp);

        priority_queue<int> pq; // {stores the duration}
        int curr_time = 0;

        for (int i = 0; i < n; i++)
        {
            if (curr_time + courses[i][0] <= courses[i][1])
            {
                pq.push(courses[i][0]);
                curr_time += courses[i][0];
            }
            else if (!pq.empty() && pq.top() > courses[i][0])
            {
                curr_time -= pq.top() - courses[i][0];
                pq.pop();
                pq.push(courses[i][0]);
            }
        }

        return pq.size();
    }
};

int main()
{

    return 0;
}