// Date: Sun, 25 Nov 2018 03:01:46 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int t, a, b, c, d;
	cin >> t >> a >> b >> c >> d;
	cout << max({0, (a <= t ? b : 0), (c <= t ? d : 0), (a + c <= t ? b + d : 0)}) << endl;

	return 0;
}
