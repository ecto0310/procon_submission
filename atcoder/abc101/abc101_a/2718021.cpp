// Date: Sat, 23 Jun 2018 12:01:16 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		if (s[i] == '+')
			ans++;
		else
			ans--;
	}
	cout << ans << endl;

	return 0;
}
