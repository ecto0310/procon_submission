// Date: Wed, 05 Dec 2018 07:21:57 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	long long n, m, d;
	cin >> n >> m >> d;
	cout << fixed << setprecision(7) << (long long)2 * (n - d) / (double)(n * n) * (m - 1) / (d == 0 ? 2 : 1) << endl;

	return 0;
}
