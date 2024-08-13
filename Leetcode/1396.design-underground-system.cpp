#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem
{
public:
    unordered_map<int, pair<string, int>> checkIn_mp;  // {id -> {board, timeofBoard}}
    unordered_map<string, pair<int, int>> checkOut_mp; // {route -> {timetaken, count}}

    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        checkIn_mp[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        string startStation = checkIn_mp[id].first;
        int startTime = checkIn_mp[id].second;

        string endStation = stationName;
        int endTime = t;

        string route = startStation + "_" + endStation;

        int timeTaken = t - startTime;

        checkOut_mp[route].first += timeTaken;
        checkOut_mp[route].second += 1;

        checkIn_mp.erase(id);
    }

    double getAverageTime(string startStation, string endStation)
    {
        string route = startStation + "_" + endStation;

        auto &it = checkOut_mp[route];

        double totalTime = it.first;
        double attendees = it.second;

        return totalTime / attendees;
    }
};

int main()
{

    return 0;
}