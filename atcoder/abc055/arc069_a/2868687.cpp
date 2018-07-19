// Date: Thu, 19 Jul 2018 11:03:58 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	long long n, m;
	cin >> n >> m;
	cout << min(n, m / 2) + (n < m / 2 ? (m - 2 * n) / 4 : 0) << endl;

	return 0;
}
