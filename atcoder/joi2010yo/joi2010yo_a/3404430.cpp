// Date: Sun, 14 Oct 2018 09:21:49 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < 9; i++)
	{
		int b;
		cin >> b;
		n -= b;
	}
	cout << n << endl;

	return 0;
}
