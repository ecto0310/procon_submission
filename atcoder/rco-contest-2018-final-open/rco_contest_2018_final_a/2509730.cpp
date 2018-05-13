// Date: Sun, 13 May 2018 12:14:10 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < k; i++)
	{
		int x = rand() % (n + 1) - 1, y = rand() % (n + 1) - 1;
		if(x == -1 || y == -1)cout << "-1 -1" << endl;
		else cout << x << " " << y << endl;
	}

	return 0;
}
