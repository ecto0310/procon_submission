// Date: Sat, 16 Jun 2018 16:54:56 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 1, tmp = 1;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if(a == 1)tmp++;
		else
		{
			ans = max(ans, tmp);
			tmp = 1;
		}
	}
	ans = max(ans, tmp);
	cout << ans << endl;

	return 0;
}
