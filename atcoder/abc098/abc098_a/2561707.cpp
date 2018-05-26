// Date: Sat, 26 May 2018 12:00:36 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	cout << max({a + b,a - b,a*b}) << endl;
	
	return 0;
}
