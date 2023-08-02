#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int t = 0;
    stack<char> pilha;
    string c;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> c;
        for (int j = 0; j < c.length(); j++)
        {
            switch (c[j])
            {
            case '{':
                pilha.push('{'); // {{}]}
                break;
            case '(':
                pilha.push('(');
                break;
            case '[':
                pilha.push('[');
                break;
            default:
                char e;
                if (!pilha.empty()) {
                    e = pilha.top();
                }
                else{
                    cout << "N" << endl;
                        while (!pilha.empty())
                        {
                            pilha.pop();
                        }
                        j = c.length();
                         break;
                }
                    

                if (e == '{')
                {
                    if (c[j] != '}')
                    {
                        cout << "N" << endl;
                        while (!pilha.empty())
                        {
                            pilha.pop();
                        }
                        j = c.length();
                         break;
                    }
                    else {
                        if(j == c.length()-1) {
                            cout << "S" << endl;
                        } 
                    } 
                }
                else if (e == '[')
                {
                    if (c[j] != ']')
                    {
                        cout << "N" << endl;
                         while (!pilha.empty()) {
                            pilha.pop();
                        }
                        j = c.length();
                         break;
                    }
                    else {
                        if(j == c.length()-1) {
                            cout << "S" << endl;
                        } 
                    } 
                }
                else if (e == '(')
                {
                    if (c[j] != ')')
                    {
                        cout << "N" << endl;
                        while (!pilha.empty()) {
                            pilha.pop();
                        }
                        j = c.length();
                         break;
                    }
                    else {
                        if(j == c.length()-1) {
                            cout << "S" << endl;
                        } 
                    } 
                }
                pilha.pop();
            }
        }
    }
    return 0;
}