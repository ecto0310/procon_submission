// Date: Tue, 17 Jul 2018 12:40:39 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, d;
	cin >> a >> d;
	cout << max((a + 1) * d, a * (d + 1)) << endl;

	return 0;
}
