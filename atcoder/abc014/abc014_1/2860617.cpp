// Date: Tue, 17 Jul 2018 13:09:14 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	cout << (a % b == 0 ? 0 : b - a % b) << endl;

	return 0;
}
