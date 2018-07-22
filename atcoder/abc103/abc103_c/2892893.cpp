// Date: Sun, 22 Jul 2018 09:29:28 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, a[3000];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += a[i] - 1;
	cout << ans << endl;

	return 0;
}
