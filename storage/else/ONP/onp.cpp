/*
	Odwrotna notacja polska
	https://pl.wikipedia.org/wiki/Odwrotna_notacja_polska
*/
#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

int prio(char c)
{
    switch(c)
    {
        case '+': ;
        case '-': return 1;
        case '*': ;
        case '/': return 2;
        case '^': return 3;
    }
    return 0;
}

void ONP(string symb)
{
    string wynik = "";
    stack <char> stos;
    for (int i=0; i < (int)symb.size(); i++)
    {
        int t = symb[i];

        switch(t)
        {
            case '(':
                stos.push(t);
                break;

            case ')':
                while (stos.top() != '(')
                {
                    printf("%c", stos.top());
                    stos.pop();
                }
                stos.pop();
                break;

            case '+' : ;
            case '-' : ;
            case '*' : ;
            case '/' : ;
            case '^' :
                while (!stos.empty())
                {
                    if ((prio(t) == 3) || (prio(t) > prio(stos.top())))
                        break;
                    printf("%c", stos.top());
                    stos.pop();
                }
                stos.push(t);
                break;

            default:
                printf("%c", t);
                break;
        }
    }
}

int main () {

    int n;
    scanf("%d", &n);
    string odp[100];

    for (int i=-1; i < n; i++)
    {
        getline(cin, odp[i]);
    }

    for (int i=0; i < n; i++)
    {
        ONP(odp[i]);
        printf("\n");
    }

    return 0;
}
