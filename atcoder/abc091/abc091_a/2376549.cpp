// Date: Wed, 18 Apr 2018 14:00:49 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	if(a + b < c)cout << "No" << endl;
	else cout << "Yes" << endl;

	return 0;
}
