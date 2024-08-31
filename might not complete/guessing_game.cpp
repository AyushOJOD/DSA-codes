#include <bits/stdc++.h>
using namespace std;

int generateRandom(int n)
{
    return rand() % n + 1;
}

int main()
{
    srand(time(0));

    int randomNum = generateRandom(10);
    int userGuess;

    cout << "We have a number b/w 1 to 10 try and guess it" << endl;

    while (true)
    {
        cout << "Enter your guess" << endl;
        cin >> userGuess;

        if (userGuess == randomNum)
        {
            cout << "Congo!! you guessed it correct!" << endl;
            break;
        }
        else if (userGuess > randomNum)
        {
            cout << "The guess is higher than expected" << endl;
        }
        else
        {
            cout << "The guess is lower than expected" << endl;
        }
    }

    return 0;
}