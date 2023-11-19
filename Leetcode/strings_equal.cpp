#include <bits/stdc++.h>
using namespace std;

int findMinimumOperations(string s1, string s2, string s3)
{
    int count;
    int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();

    int i = 0;
    while (i < min({n1, min(n2, n3)}) && s1[i] == s2[i] && s2[i] == s3[i])
        i++;

    count = n1 + n2 + n3 - 3 * i;

    if (i == 0)
        return -1;

    return count;
}

int main()
{

    return 0;
}