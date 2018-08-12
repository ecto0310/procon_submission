// Date: Sun, 12 Aug 2018 10:06:10 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string ans;
	while (n)
	{
		ans = (n % 2 == 0 ? '0' : '1') + ans;
		n = ceil((double)n / (double)-2);
	}
	if (ans == "")
		cout << 0 << endl;
	else
		cout << ans << endl;

	return 0;
}
