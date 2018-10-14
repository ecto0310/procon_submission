// Date: Sun, 14 Oct 2018 09:09:40 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a = 0, b = 0;
	for (int i = 0; i < 4; i++)
	{
		int t;
		cin >> t;
		a += t;
	}
	for (int i = 0; i < 4; i++)
	{
		int t;
		cin >> t;
		b += t;
	}
	cout << max(a, b) << endl;

	return 0;
}
