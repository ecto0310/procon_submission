// Date: Tue, 17 Jul 2018 13:05:18 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int ans = 0;
	for (int i = 0; i < 3; i++)
	{
		int s, e;
		cin >> s >> e;
		ans += s * e / 10;
	}
	cout << ans << endl;

	return 0;
}
