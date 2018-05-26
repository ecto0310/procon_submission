// Date: Sat, 26 May 2018 12:05:18 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int cnt = 0;
		bool use[26] = {false};
		for(int j = 0; j < i; j++)use[s[j] - 'a'] = true;
		for(int j = i; j < n; j++)
		{
			if(use[s[j] - 'a'])
			{
				use[s[j] - 'a'] = false;
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	
	return 0;
}
