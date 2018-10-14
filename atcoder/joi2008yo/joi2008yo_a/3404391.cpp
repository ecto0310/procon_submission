// Date: Sun, 14 Oct 2018 09:12:34 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	n = 1000 - n;
	int m[6] = {500, 100, 50, 10, 5, 1}, ans = 0;
	for (int i = 0; i < 6; i++)
	{
		ans += n / m[i];
		n %= m[i];
	}
	cout << ans << endl;

	return 0;
}
