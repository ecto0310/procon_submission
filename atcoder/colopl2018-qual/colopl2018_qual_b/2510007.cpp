// Date: Sun, 13 May 2018 13:11:53 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n, x;
	string s;
	cin >> n >> x >> s;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		if(s[i] == '0')ans += t;
		else ans += min(t, x);
	}
	cout << ans << endl;

	return 0;
}
