#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string str)
{
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            s.push(str[i]);
        }
        else if (str[i] == '}' && !s.empty() && s.top() == '{')
        {
            s.pop();
        }
        else if (str[i] == ']' && !s.empty() && s.top() == '[')
        {
            s.pop();
        }
        else if (str[i] == ')' && !s.empty() && s.top() == '(')
        {
            s.pop();
        }
        else
        {
            return false;
        }
    }
    return s.empty();
}

int main()
{
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (isBalanced(expression))
    {
        cout << "Expression is balanced." << endl;
    }
    else
    {
        cout << "Expression is not balanced." << endl;
    }

    return 0;
}
