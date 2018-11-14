// Date: Wed, 14 Nov 2018 14:12:58 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (x >> i & 1)
			ans += a;
	}
	cout << ans << endl;

	return 0;
}
