// Date: Sun, 08 Jul 2018 11:03:28 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	int group[13] = {-1, 0, 2, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0};
	if (group[x] == group[y])
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
