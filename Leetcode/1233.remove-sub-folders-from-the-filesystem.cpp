#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        unordered_set<string> set(begin(folder), end(folder));
        vector<string> res;

        for (string &currFolder : folder)
        {
            bool isSubFolder = false;
            string temp = currFolder;

            while (!currFolder.empty())
            {
                auto pos = currFolder.find_last_of('/');

                currFolder = currFolder.substr(0, pos);

                if (set.find(currFolder) != set.end())
                {
                    // We got a parent folder
                    isSubFolder = true;
                    break;
                }
            }

            if (!isSubFolder)
            {
                res.push_back(temp);
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}