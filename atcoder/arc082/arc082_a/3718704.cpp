// Date: Tue, 04 Dec 2018 17:02:33 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> cnt(100001, 0);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		cnt[a]++;
	}
	int ans = 0;
	for (int i = 0; i < 100000;i++)
		ans = max(ans, (i == 0 ? 0 : cnt[i - 1]) + cnt[i] + cnt[i + 1]);
	cout << ans << endl;

	return 0;
}
