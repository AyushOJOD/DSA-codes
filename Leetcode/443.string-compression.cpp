#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        int write = 0, read = 0;

        while (read < n)
        {
            char curr = chars[read];
            int cnt = 0;

            while (read < n && curr == chars[read])
            {
                cnt++;
                read++;
            }

            chars[write++] = curr;

            if (cnt > 1)
            {
                string cnt_str = to_string(cnt);
                for (char ch : cnt_str)
                {
                    chars[write++] = ch;
                }
            }
        }

        return write;
    }
};

int main()
{

    return 0;
}