// Date: Sun, 20 May 2018 14:17:24 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	long long k;
	cin >> a >> b >> c >> k;
	if(k % 2 == 1)cout << b - a << endl;
	else cout << a - b << endl;

	return 0;
}
