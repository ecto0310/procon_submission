// Date: Tue, 17 Jul 2018 12:47:41 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int l1, l2, l3;
	cin >> l1 >> l2 >> l3;
	if (l1 == l2)
		cout << l3 << endl;
	else if (l1 == l3)
		cout << l2 << endl;
	else
		cout << l1 << endl;

	return 0;
}
