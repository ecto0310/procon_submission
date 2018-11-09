// Date: Fri, 09 Nov 2018 02:01:31 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int l, h, n;
	cin >> l >> h >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		cout << (a > h ? -1 : max(0, l - a)) << endl;
	}

	return 0;
}
