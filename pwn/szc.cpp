/*
    Zadanie: Flagi
    - wziąć dzielniki n
    - dla każdego dzielnika x sprawdzić sume prefiksową na przedziałach długości x 
*/
#include <bits/stdc++.h>

using namespace std;

constexpr int MxN = 5e5+55;
int A[MxN], p[MxN];
int ans = 0, n;

// Suma na przedziale [a, b]
int prefsum(int a, int b) { return p[b+1] - p[a]; }

// Sprawdzanie przedziałów o długości k
void checksegments(int k)
{
    int res = 0;
    for (int i=0; i<=n-k; i+=k)
    {
        if (prefsum(i, i+k-1) >= 1)
            res++;
        else
        {
            res = 0;
            break;
        }
    }

    ans = max(ans, res);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    
    // Wczytywanie tablicy
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> A[i];
        
    // Obliczanie tablicy sum prefiksowych
    int c = 0;
    for (int i=0; i<n-2; i++)
    {
        if (A[i] < A[i+1] && A[i+1] > A[i+2])
            c++;
        p[i+2] = c;
    }
    p[n-1] = p[n] = c;

    // Wyznaczanie dzielników liczby n
    for (int d=1; d*d<=n; d++)
    {
        if (n % d == 0)
        {
            if (n / d == d)
                checksegments(d);
            else
            {
                checksegments(d);
                checksegments(n/d);
            }
        }
    }

    cout << ans << "\n";
    
    return 0;
}
