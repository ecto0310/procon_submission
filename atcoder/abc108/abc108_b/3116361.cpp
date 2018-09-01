// Date: Sat, 01 Sep 2018 12:40:34 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << x2 + y1 - y2 << " " << y2 + x2 - x1 << " " << x1 + y1 - y2 << " " << y1 + x2 - x1 << endl;

	return 0;
}
