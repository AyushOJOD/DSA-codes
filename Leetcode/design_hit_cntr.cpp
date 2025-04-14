#include <bits/stdc++.h>
using namespace std;

class HitCounter
{
public:
    unordered_set<int> time;

    HitCounter()
    {
    }

    void hit(int timestamp)
    {
        time.insert(timestamp);
    }

    int getHits(int timestamp)
    {
        int cnt = 0;

        for (int i = 0; i < 300 && (timestamp - i - 1 >= 0); i++)
        {
            int currTime = timestamp - i - 1;

            if (time.find(currTime) != time.end())
            {
                cnt++;
            }
        }

        return cnt;
    }
};

int main()
{
    HitCounter counter;

    // Performing the hit operations
    counter.hit(1);
    counter.hit(2);
    counter.hit(3);

    // Performing the getHits operations and printing the results
    std::cout << "getHits(3): " << counter.getHits(3) << std::endl; // Expected: 3

    counter.hit(301); // This hit is outside the 300-second window

    std::cout << "getHits(301): " << counter.getHits(301) << std::endl; // Expected: 3

    return 0;
}