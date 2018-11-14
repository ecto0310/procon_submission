// Date: Wed, 14 Nov 2018 14:48:39 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	map<string, int> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		m[s]++;
	}
	int ma = 0;
	string ans;
	for (pair<string, int> t : m)
		if (ma < t.second)
		{
			ma = t.second;
			ans = t.first;
		}
	cout << ans << endl;

	return 0;
}
