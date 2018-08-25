// Date: Sat, 25 Aug 2018 05:43:27 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	for (int i = 0; i < 100000000; i++)
	{
		int tx = y - z, ty = z - x, tz = x - y;
		if (tx == 0 || ty == 0 || tz == 0)
		{
			cout << i + 2 << endl;
			return 0;
		}
		else
		{
			x = tx;
			y = ty;
			z = tz;
		}
	}
	cout << -1 << endl;

	return 0;
}
