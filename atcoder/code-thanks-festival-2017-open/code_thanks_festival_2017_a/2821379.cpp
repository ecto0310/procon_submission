// Date: Tue, 10 Jul 2018 07:44:44 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int ans = 0;
	for (int i = 0; i < 8; i++)
	{
		int t;
		cin >> t;
		ans = max(ans, t);
	}
	cout << ans << endl;

	return 0;
}
