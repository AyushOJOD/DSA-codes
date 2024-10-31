#include <bits/stdc++.h>
using namespace std;

struct App
{
    string name;
    App() : name("") {}
    App(string n) : name(n) {}
};

class TaskBar
{
public:
    stack<App> st;

    App clickOnApp(App app)
    {
        st.push(app);
        return st.top();
    }

    App altTab(int TabClicks)
    {
        if (st.empty() || TabClicks == 0)
        {
            return st.empty() ? App("") : st.top();
        }

        int reqClicks = TabClicks % st.size();

        stack<App> temp;
        for (int i = 0; i < reqClicks; i++)
        {
            temp.push(st.top());
            st.pop();
        }

        App curr = st.top();
        st.pop();

        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }

        st.push(curr);
        return st.top();
    }

    App closeCurrApp()
    {
        st.pop();
        if (!st.empty())
        {
            return st.top();
        }
        return App("");
    }
};

int main()
{
    TaskBar tb;
    App app1 = {"Music Player"};
    App app2 = {"Video Player"};
    App app3 = {"Photo Viewer"};
    App app4 = {"Game"};

    tb.clickOnApp(app1);
    tb.clickOnApp(app2);
    tb.clickOnApp(app3);
    tb.clickOnApp(app4);

    cout << tb.altTab(3).name << endl; // Expected: "Music Player" (3 % 4 = 3)
    cout << tb.altTab(5).name << endl; // Expected: "Photo Viewer" (5 % 4 = 1)

    return 0;
}