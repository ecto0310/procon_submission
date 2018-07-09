// Date: Mon, 09 Jul 2018 14:00:38 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, k, x, y;
	cin >> n >> k >> x >> y;
	if (n > k)
		cout << k * x + (n - k) * y << endl;
	else
		cout << n * x << endl;

	return 0;
}
