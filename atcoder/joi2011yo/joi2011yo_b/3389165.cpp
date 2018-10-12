// Date: Fri, 12 Oct 2018 15:38:46 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string t;
		cin >> t;
		int size = t.size();
		for (int j = 0; j < size; j++)
		{
			bool ok = true;
			for (int k = 0; k < s.size(); k++)
				if (t[(j + k) % size] != s[k])
					ok = false;
			if (ok)
			{
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;

	return 0;
}
