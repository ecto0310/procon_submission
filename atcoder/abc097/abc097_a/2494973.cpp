// Date: Sat, 12 May 2018 12:02:51 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d))cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
