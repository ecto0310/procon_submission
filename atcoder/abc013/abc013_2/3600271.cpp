// Date: Wed, 14 Nov 2018 14:14:39 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	cout << min(abs(a - b), abs(10 - abs(a - b))) << endl;

	return 0;
}
