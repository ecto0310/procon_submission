// Date: Sat, 30 Jun 2018 17:21:13 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int size = s.size();
	map<int, int> m;
	int ans = 0, cnt = 0;
	for (int i = 0; i < size; i++)
	{
		if(s[i]=='(')
		{
			cnt++;
			m[cnt]++;
		}
		else
		{
			ans += m[cnt];
			m[cnt + 1] = 0;
			cnt--;
		}
	}
	cout << ans << endl;

	return 0;
}
