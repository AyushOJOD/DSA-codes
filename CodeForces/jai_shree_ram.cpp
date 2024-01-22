#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> points[i].first >> points[i].second;
    }

    unordered_set<pair<int, int>> point_set(points.begin(), points.end());

    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int px = points[i].first, py = points[i].second;
            int rx = points[j].first, ry = points[j].second;

            int qx = (px + rx) / 2;
            int qy = (py + ry) / 2;

            if (point_set.find({qx, qy}) != point_set.end())
            {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
