// Date: Wed, 07 Nov 2018 14:30:06 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int sum = 0, ans = n;
	for (int i = n - 1; i >= 0; i--)
		if (sum + v[i] < k)
			sum += v[i];
		else
			ans = i;
	cout << ans << endl;

	return 0;
}
