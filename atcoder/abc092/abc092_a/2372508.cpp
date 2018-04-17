// Date: Tue, 17 Apr 2018 12:20:34 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << min(a, b) + min(c, d) << endl;

	return 0;
}
