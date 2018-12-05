// Date: Wed, 05 Dec 2018 06:42:51 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	map<int, int> w;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		w[tmp]++;
	}
	bool ok = true;
	int m;
	cin >> m;
	map<int, int> q;
	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		q[tmp]++;
		if (w[tmp] < q[tmp])
			ok = false;
	}
	cout << (ok ? "YES" : "NO") << endl;

	return 0;
}
