// Date: Sun, 12 Aug 2018 09:14:30 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	cout << (n % k == 0 ? 0 : 1) << endl;

	return 0;
}
