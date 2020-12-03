#include <bits/stdc++.h>
using namespace std;

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

int prec(char a)
{
    if (a == '^')
        return 3;
    else if (a == '*' || a == '/')
        return 2;
    else if (a == '+' || a == '-')
        return 1;
    else
        return -1;
}
float operation(float a, float b, char op)
{
    if (op == '+')
        return b + a;
    else if (op == '-')
        return b - a;
    else if (op == '*')
        return b * a;
    else if (op == '/')
        return b / a;
    else if (op == '^')
        return pow(b, a);
    else
        return 0;
}
string infixToPostfix(string s)
{
    int l = s.length();
    char stack[l];
    int top = -1;
    string news;
    for (int i = 0; i < l;)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            while (s[i] >= '0' && s[i] <= '9')
            {
                news = news + s[i];
                i++;
            }
            news = news + " ";
        }
        else
        {
            while (top != -1 && prec(s[i]) <= prec(stack[top]))
            {
                char c = stack[top];
                top--;
                news = news + c;
            }
            top++;
            stack[top] = s[i];
            i++;
        }
    }
    while (top != -1)
    {
        char c = stack[top];
        top--;
        news = news + c;
    }
    return news;
}
void PostfixEvaluation(string s)
{
    int l = s.length();
    int stack[l];
    int top = -1;
    for (int i = 0; i < l;)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            string a;
            while (s[i] >= '0' && s[i] <= '9')
            {
                a = a + s[i];
                i++;
            }
            top++;
            stack[top] = stoi(a);
        }
        else if (s[i] == ' ')
            i++;
        else
        {
            float a = stack[top];
            float b = stack[top - 1];
            top--;
            stack[top] = operation(a, b, s[i]);
            i++;
        }
    }
    cout << stack[top] << "\n";
}

int main()
{
    string infix, temp;
    cout << "Enter the Infix Expression : ";
    getline(cin, temp);
    infix = temp;
    string postfix = infixToPostfix(infix);
    PostfixEvaluation(postfix);
}