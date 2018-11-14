// Date: Wed, 14 Nov 2018 14:51:31 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 100;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		ans = min(ans, t);
	}
	cout << ans << endl;

	return 0;
}
