// Date: Sun, 01 Jul 2018 11:49:42 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <numeric>

using namespace std;

int gcd(int a, int b)
{
	int c;
	while (a != 0)
	{
		c = a;
		a = b % a;
		b = c;
	}
	return b;
}

int main()
{
	int n;
	cin >> n;
	cout << (2 * n) / gcd(2, n) << endl;

	return 0;
}
