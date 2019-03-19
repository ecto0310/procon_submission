// Date: Tue, 19 Mar 2019 11:39:36 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
  long long n, m;
	cin >> n >> m;
	cout << min(n, m / 2) + (n < m / 2 ? (m - 2 * n) / 4 : 0) << endl;

  return 0;
}
