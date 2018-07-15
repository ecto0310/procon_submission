// Date: Sun, 15 Jul 2018 14:05:33 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << max(c / a, c / b) << endl;

	return 0;
}
