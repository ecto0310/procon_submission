// Date: Fri, 09 Nov 2018 02:13:35 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	double ans = abs(n % 12 * 30 + 0.5 * m - 6 * m);
	cout << fixed << setprecision(4) << (ans > 180 ? 360 - ans : ans) << endl;
	
	return 0;
}
