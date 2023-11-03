#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path)
{
    stack<string> st;
    string result;

    for (int i = 0; i < path.size(); i++)
    {
        if (path[i] == '/')
        {
            continue;
        }

        string temp;
        while (i < path.size() && path[i] != '/')
        {
            temp += path[i];
            i++;
        }

        if (temp == ".")
        {
            continue;
        }
        else if (temp == "..")
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            st.push(temp);
        }
    }

    while (!st.empty())
    {
        result = "/" + st.top() + result;
        st.pop();
    }

    if (result.size() == 0)
    {
        return '/';
    }
    return res;
}

int main()
{

    return 0;
}