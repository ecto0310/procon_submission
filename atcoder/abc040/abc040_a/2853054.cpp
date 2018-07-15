// Date: Sun, 15 Jul 2018 14:02:29 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;
	cout << min(n - x, x - 1) << endl;

	return 0;
}
