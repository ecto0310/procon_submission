// Date: Sat, 15 Dec 2018 04:47:43 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int i = 1, cnt = 0;
	for (; cnt < c; i++)
	{
		if (i % 7 == 0)
			cnt += b;
		cnt += a;
	}
	cout << i - 1 << endl;

	return 0;
}
