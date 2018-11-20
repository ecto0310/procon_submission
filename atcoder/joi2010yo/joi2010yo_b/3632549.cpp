// Date: Tue, 20 Nov 2018 15:23:19 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> s(n), d(m);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < m; i++)
		cin >> d[i];
	int now = 1;
	for (int i = 0; i < m; i++)
	{
		now += d[i];
		now += s[now - 1];
		if (now >= n)
		{
			cout << i + 1 << endl;
			return 0;
		}
		cerr << now << endl;
	}

	return 0;
}
