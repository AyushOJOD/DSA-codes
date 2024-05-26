#include <bits/stdc++.h>
using namespace std;

string compressedString(string word)
{
    string comp = "";
    int count = 0;
    char letter;

    if (word.size() == 1)
        return word;

    for (int i = 0; i < word.size(); i++)
    {
        letter = word[i];
        count = 0;

        while (i < word.size() && word[i] == letter && count <= 8)
        {
            count++;
            i++;
        }

        comp += to_string(count) + letter;

        i--;
    }

    return comp;
}

int main()
{

    string word;
    cin >> word;

    cout << compressedString(word) << endl;

    return 0;
}