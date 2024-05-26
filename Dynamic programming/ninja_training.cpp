#include <bits/stdc++.h>
using namespace std;

// int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &prev)
// {

//     if (prev[day][last] != -1)
//     {
//         return prev[day][last];
//     }

//     if (day == 0)
//     { // base case
//         int maxi = 0;
//         for (int i = 0; i < 3; i++)
//         {
//             if (i != last)
//             {
//                 maxi = max(maxi, points[0][i]);
//             }
//         }
//         return prev[day][last] = maxi;
//     }

//     int maxi = 0;

//     for (int i = 0; i < 3; i++)
//     {
//         if (i != last)
//         {
//             maxi = max(maxi, points[day][i] + f(day - 1, i, points, prev));
//         }
//     }

//     return prev[day][last] = maxi;
// }

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.

    vector<int> prev(4, 0);
    // int max = f(n - 1, 3, points, prev);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(prev[0][0], max(prev[0][1], prev[0][2]));

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;

            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }

    return prev[3];
}

int main()
{

    return 0;
}