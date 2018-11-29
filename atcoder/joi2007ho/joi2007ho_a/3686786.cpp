// Date: Thu, 29 Nov 2018 14:51:40 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	queue<int> a;
	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		int t;
		cin >> t;
		a.push(t);
		sum += t;
	}
	int ans = sum;
	for (int i = 0; i < n - k; i++)
	{
		sum -= a.front();
		a.pop();
		int t;
		cin >> t;
		a.push(t);
		sum += t;
		ans = max(ans, sum);
	}
	cout << ans << endl;

	return 0;
}
