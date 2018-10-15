// Date: Mon, 15 Oct 2018 15:15:30 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n % 2 == 0)
		cout << n - 1 << endl;
	else
		cout << n + 1 << endl;

	return 0;
}
