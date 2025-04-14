#include <bits/stdc++.h>
using namespace std;

class Twitter
{
public:
    int count;
    unordered_map<int, vector<pair<int, int>>> tweets; //{id -> vector(cnt, tweetid)}
    unordered_map<int, unordered_set<int>> followings; //{user -> followeeIds}

    Twitter()
    {
        count = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({count, tweetId});
        count++;
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<pair<int, int>> pq; // {count, tweetId}

        vector<int> feed;

        unordered_set<int> following = followings[userId];
        following.insert(userId);

        for (int followeeId : following)
        {
            vector<pair<int, int>> fPosts = tweets[followeeId];

            for (int i = 0; i < fPosts.size(); i++)
            {
                pq.push({fPosts[i].first, fPosts[i].second});
            }
        }

        int cnt = 0;
        while (!pq.empty() && cnt < 10)
        {
            feed.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }

        return feed;
    }

    void follow(int followerId, int followeeId)
    {
        followings[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        followings[followerId].erase(followeeId);
    }
};

int main()
{

    return 0;
}