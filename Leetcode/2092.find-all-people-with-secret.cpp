#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string canReachSafely(int M, int N, vector<vector<int>> &lamps)
{
    for (auto &lamp : lamps)
    {
        int x = lamp[0];
        int y = lamp[1];
        int r = lamp[2];

        if (x - r <= 0 || x + r >= M)
        {
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int M, N;
        cin >> M >> N;

        vector<vector<int>> lamps(N, vector<int>(3));
        for (int i = 0; i < N; ++i)
        {
            cin >> lamps[i][0] >> lamps[i][1] >> lamps[i][2];
        }

        cout << canReachSafely(M, N, lamps) << endl;
    }

    return 0;
}
