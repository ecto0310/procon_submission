// Date: Sun, 18 Nov 2018 12:03:27 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		m[a]++;
	}
	for (pair<int, int> t : m)
	{
		if (t.first < t.second)
			ans += t.second - t.first;
		else if (t.first > t.second)
			ans += t.second;
	}
	cout << ans << endl;

	return 0;
}
