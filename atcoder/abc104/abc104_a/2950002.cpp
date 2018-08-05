// Date: Sun, 05 Aug 2018 12:00:59 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int r;
	cin >> r;
	if (r < 1200)
		cout << "ABC" << endl;
	else if (r < 2800)
		cout << "ARC" << endl;
	else
		cout << "AGC" << endl;

	return 0;
}
