// Date: Tue, 17 Apr 2018 10:39:51 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, x;
	cin >> a >> b >> x;
	if( a <= x && a + b >= x )cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
