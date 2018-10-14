// Date: Sun, 14 Oct 2018 09:27:33 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;
	cout << l - max((a + c - 1) / c, (b + d - 1) / d) << endl;

	return 0;
}
