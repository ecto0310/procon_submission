// Date: Sat, 15 Dec 2018 04:48:12 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < n - 1; i++)
		if (s[i] != s[i + 1])
		{
			ans++;
			i++;
		}
	cout << ans << endl;

	return 0;
}
