// Date: Tue, 17 Jul 2018 12:39:05 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, n;
	cin >> a >> b >> n;
	for (int i = n;; i++)
		if (i % a == 0 && i % b == 0)
		{
			cout << i << endl;
			break;
		}

	return 0;
}
