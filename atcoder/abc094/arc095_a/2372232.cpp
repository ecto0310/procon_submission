// Date: Tue, 17 Apr 2018 11:14:26 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int x[200000];
int t[200000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for( int i = 0; i < n; i++ )cin >> x[i];
	memcpy(t, x, sizeof(int) * n);
	sort(x, x + n);
	int s = x[( n + 1 ) / 2];
	int c[2] = { x[( n + 1 ) / 2],x[( n + 1 ) / 2 - 1] };
	for( int i = 0; i < n; i++ )
	{
		if( s > t[i] )cout << c[0] << endl;
		else cout << c[1] << endl;
	}

	return 0;
}
