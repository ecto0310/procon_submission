// Date: Sun, 25 Nov 2018 04:43:02 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	while (0 < x && 0 < y)
		if (x < y)
		{
			x -= 1;
			y -= 3;
		}
		else
		{
			x -= 3;
			y -= 1;
		}
	cout << (x == 0 && y == 0 ? "Yes" : "No") << endl;

	return 0;
}
