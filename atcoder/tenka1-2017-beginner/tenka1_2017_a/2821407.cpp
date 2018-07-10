// Date: Tue, 10 Jul 2018 07:52:28 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '1')
			ans++;
	cout << ans << endl;

	return 0;
}
