// Date: Tue, 13 Nov 2018 08:17:25 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	map<int, bool> m;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (m[a])
			ans++;
		m[a] = true;
	}
	cout << ans << endl;

	return 0;
}
