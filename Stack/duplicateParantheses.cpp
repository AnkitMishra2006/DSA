#include <iostream>
#include <stack>
using namespace std;

// Program to check for duplicate parentheses in an expression
bool checkDuplicateParentheses(string expression)
{
    stack<char> s;
    for (char ch : expression)
    {
        if (ch == ')')
        {
            int count = 0;
            while (!s.empty() && s.top() != '(')
            {
                s.pop();
                count++;
            }
            if (count < 1)
            {
                return true; // Duplicate parentheses found
            }
            s.pop(); // Pop the '('
        }
        else
        {
            s.push(ch);
        }
    }
    return false; // No duplicate parentheses found
}

int main()
{
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (checkDuplicateParentheses(expression))
    {
        cout << "Duplicate parentheses found." << endl;
    }
    else
    {
        cout << "No duplicate parentheses found." << endl;
    }

    return 0;
}