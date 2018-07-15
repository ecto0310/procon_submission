// Date: Sun, 15 Jul 2018 14:07:23 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	int ans = 0, tmp = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'I')
			tmp++;
		else
			tmp--;
		ans = max(ans, tmp);
	}
	cout << ans << endl;

	return 0;
}
