// Date: Sun, 15 Jul 2018 13:12:13 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int m = 0, ans;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a > m)
		{
			ans = a + b;
			m = a;
		}
	}
	cout << ans << endl;

	return 0;
}
