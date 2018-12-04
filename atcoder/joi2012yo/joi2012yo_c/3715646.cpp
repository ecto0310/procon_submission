// Date: Tue, 04 Dec 2018 07:09:04 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<int> d(n);
	for (int i = 0; i < n; i++)
		cin >> d[i];
	sort(d.begin(), d.end(), greater<int>());
	int ans = 0, sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += d[i];
		ans = max(ans, (c + sum) / (a + b * (i + 1)));
	}
	cout << ans << endl;

	return 0;
}
