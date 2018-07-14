// Date: Sat, 14 Jul 2018 12:02:11 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[100];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	for (int i = 1; i < n; i++)
		if (a[i] == a[i - 1])
		{
			ans++;
			a[i] = -1;
		}
	cout << ans << endl;

	return 0;
}
