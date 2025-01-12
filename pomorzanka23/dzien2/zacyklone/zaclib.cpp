#include <bits/stdc++.h>
#include "zac.h"

using namespace std;

namespace
{
    vector<bool> transform(string s)
    {
        vector<bool> res(s.size());
        for (int i = 0; i < (int)s.size(); i++)
            res[i] = s[i] - '0';
        return res;
    }
    vector<bool> shift(vector<bool> v, int k)
    {
        vector<bool> res(v.size());
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            res[i] = v[(i + k) % n];
        }
        return res;
    }
    void die(string error)
    {
        cout << error << '\n';
        exit(0);
    }

    void run()
    {
        int n, k, p;
        cin >> n >> k;
        vector<vector<bool>> wyj, wyj2, wej;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s >> p;
            vector<bool> c = transform(s);
            wej.push_back(c);
            vector<bool> res = shift(zapisz(c), p);
            wyj.push_back(res);
            if (res.size() > c.size() + 100)
                die("Za długa informacja");
        }
        cout << "Zapisane informacje\n";
        for (auto i : wyj)
        {
            for (auto j : i)
                cout << j;
            cout << '\n';
        }
        for (int i = 0; i < n; i++)
        {
            wyj2.push_back(odczytaj(wyj[i]));
        }
        cout << "Odczytane informacje\n";

        for (int ii = 0; ii < wyj2.size(); ii++)
        {
            auto i = wyj2[ii];
            if (i != wej[ii]) {
                cout << "Odczytana wiadomość inna od oczekiwanej:\n";
            	cout << "powinnobyc = ";
            }
            for (auto j : i)
                cout << j;
        	cout << " jest = ";
        	for (auto j : wyj2[ii])
        		cout << j;
        	cout << "\n";
        }
    }
}
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(0);
    run();
}
