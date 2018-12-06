// Date: Thu, 06 Dec 2018 12:18:03 +0000
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
