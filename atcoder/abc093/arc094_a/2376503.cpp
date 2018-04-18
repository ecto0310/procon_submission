// Date: Wed, 18 Apr 2018 13:45:45 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	int m = max({a,b,c});
	if((a + b + c) % 2 != m % 2)m++;
	cout << (m * 3 - a - b - c)/2 << endl;

	return 0;
}
