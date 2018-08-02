// Date: Thu, 02 Aug 2018 14:12:57 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	long long x, y;
	cin >> x >> y;
	long long ans;
	for (long long i = 0; y >= x; i++)
	{
		ans = i + 1;
		x *= 2;
	}
	cout << ans << endl;

	return 0;
}
