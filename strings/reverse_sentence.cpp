// First reverse each word then reverse the whole sentence keeping in mind about the space

#include <bits/stdc++.h>
using namespace std;

void reverse(char str[], int low, int high)
{
    while (low <= high)
    {
        swap(str[low], str[high]);
        low++;
        high--;
    }
}

void reverseSentence(char str[], int n)
{
    int start = 0;
    for (int end = 0; end < n; end++)
    {
        if (str[end] == ' ')
        {
            reverse(str, start, end - 1);
            start = end + 1;
        }
    }
    reverse(str, start, n - 1);
    reverse(str, 0, n - 1); // reversing the last word because no space after the last word
}

int main()
{
    char str[] = "Welcome to Gfg";
    int n = strlen(str);

    reverseSentence(str, n);

    cout << str;

    return 0;
}