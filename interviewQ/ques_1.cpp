#include <bits/stdc++.h>
using namespace std;

// Ques: from a numpad given a number and a vector of string of words, find all the possible words that can be formed from the number

vector<string> solve(string number, vector<string> &words, unordered_map<char, string> &numpad)
{
    vector<string> res;

    for (auto it : words)
    {
        string temp = "";
        for (int i = 0; i < it.length(); i++)
        {
            temp.append(numpad[it[i]]);
        }

        if (number.find(temp) != string ::npos)
        {
            res.push_back(it);
        }
    }

    return res;
}

int main()
{

    unordered_map<char, string> numpad;

    numpad['b'] = '2';
    numpad['a'] = '2';
    numpad['c'] = '2';
    numpad['d'] = '3';
    numpad['e'] = '3';
    numpad['f'] = '3';
    numpad['g'] = '4';
    numpad['h'] = '4';
    numpad['i'] = '4';
    numpad['j'] = '5';
    numpad['k'] = '5';
    numpad['l'] = '5';
    numpad['m'] = '6';
    numpad['n'] = '6';
    numpad['o'] = '6';
    numpad['p'] = '7';
    numpad['q'] = '7';
    numpad['r'] = '7';
    numpad['s'] = '7';
    numpad['t'] = '8';
    numpad['u'] = '8';
    numpad['v'] = '8';
    numpad['w'] = '9';
    numpad['x'] = '9';
    numpad['y'] = '9';
    numpad['z'] = '9';

    string number = "3662277";
    vector<string> words = {"foo", "bar", "baz", "foobar", "emo", "cap", "car", "cat"};

    vector<string> res = solve(number, words, numpad);

    for (auto it : res)
    {
        cout << it << endl;
    }

    return 0;
}