#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Segment
{
    int length;
    int speedLimit;
};

struct BessieSegment
{
    int length;
    int speed;
};

int main()
{
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");

    int N, M;
    fin >> N >> M;

    vector<Segment> road(N);
    vector<BessieSegment> bessie(M);

    for (int i = 0; i < N; ++i)
    {
        fin >> road[i].length >> road[i].speedLimit;
    }

    for (int i = 0; i < M; ++i)
    {
        fin >> bessie[i].length >> bessie[i].speed;
    }

    int maxOverSpeedLimit = 0;
    int roadIndex = 0, bessieIndex = 0;
    int bessieDistance = 0, roadDistance = 0;

    while (roadIndex < N && bessieIndex < M)
    {
        int dist = min(road[roadIndex].length - roadDistance, bessie[bessieIndex].length - bessieDistance);

        int roadSpeed = road[roadIndex].speedLimit;
        int bessieSpeed = bessie[bessieIndex].speed;

        int overSpeedLimit = max(0, bessieSpeed - roadSpeed);

        maxOverSpeedLimit = max(maxOverSpeedLimit, overSpeedLimit);

        roadDistance += dist;
        bessieDistance += dist;

        if (roadDistance == road[roadIndex].length)
        {
            roadDistance = 0;
            roadIndex++;
        }

        if (bessieDistance == bessie[bessieIndex].length)
        {
            bessieDistance = 0;
            bessieIndex++;
        }
    }

    fout << maxOverSpeedLimit << endl;

    fin.close();
    fout.close();

    return 0;
}
