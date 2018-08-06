// Date: Mon, 06 Aug 2018 15:49:40 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
#include <numeric>

using namespace std;

int p[100000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (p[i] == i + 1)
		{
			swap(p[i], p[i + 1]);
			ans++;
		}
	cout << ans << endl;

	return 0;
}
