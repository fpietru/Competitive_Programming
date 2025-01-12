#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
	return -4*(x-2)*(x-2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	double a, b; cin >> a >> b;
	double epsilon = 1e-9;
	while (b-a > epsilon)
	{
		double m1 = a + (b-a) / 3;
		double m2 = b - (b-a) / 3;
		if (f(m1) < f(m2))
			a = m1;
		else
			b = m2;
	}
	
	cout << "Maxymalna wartość funkcji: " << f(a) << " dla argumentu: " << a << "\n";
	
	return 0;
}
