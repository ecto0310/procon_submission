// Date: Sun, 01 Jul 2018 11:33:33 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int mi = 1000000000, ma = 0;
	for (int i = 0; i < n;i++)
	{
		int a;
		cin >> a;
		ma = max(ma, a);
		mi = min(mi, a);
	}
	cout << ma - mi << endl;
	return 0;
}
