// Date: Tue, 27 Nov 2018 15:16:10 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	long long n;
	cin >> n;
	int ans = 10;
	for (long long i = 1; i <= sqrt(n); i++)
		if (n % i == 0)
		{
			int ca = 0, cb = 0;
			long long a = i, b = n / i;
			while (a)
			{
				a /= 10;
				ca++;
			}
			while (b)
			{
				b /= 10;
				cb++;
			}
			ans = min(ans, max(ca, cb));
		}
	cout << ans << endl;

	return 0;
}
