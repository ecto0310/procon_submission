// Date: Sun, 08 Jul 2018 11:17:02 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int mi = 1000, ma = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		mi = min(mi, a);
		ma = max(ma, a);
	}
	cout << ma - mi << endl;

	return 0;
}
