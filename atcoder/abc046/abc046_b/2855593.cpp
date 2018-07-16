// Date: Mon, 16 Jul 2018 08:21:04 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int ans = k;
	for (int i = 0; i < n - 1; i++)
		ans *= k - 1;
	cout << ans << endl;

	return 0;
}
