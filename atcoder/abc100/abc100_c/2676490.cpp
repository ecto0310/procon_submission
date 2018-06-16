// Date: Sat, 16 Jun 2018 12:08:24 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		while(a % 2==0)
		{
			a /= 2;
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}
