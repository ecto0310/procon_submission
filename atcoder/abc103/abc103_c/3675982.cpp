// Date: Tue, 27 Nov 2018 08:38:03 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		ans += a - 1;
	}
	cout << ans << endl;

	return 0;
}
