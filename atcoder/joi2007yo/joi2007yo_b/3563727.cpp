// Date: Thu, 08 Nov 2018 09:53:48 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	bool ok[30] = {};
	int n;
	for (int i = 0; i < 28; i++)
	{
		cin >> n;
		ok[n - 1] = true;
	}
	for (int i = 0; i < 30; i++)
		if (!ok[i])
			cout << i + 1 << endl;

	return 0;
}
