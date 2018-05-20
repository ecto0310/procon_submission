// Date: Sun, 20 May 2018 04:46:30 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int a[300][300];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			a[i][j]--;
		}
	int ret = (n != 1 ? 300 : 1);
	bool lot[300] = {false};
	for(int i = 0; i < m - 1; i++)
	{
		int reg[300] = {0};
		for(int j = 0; j < n; j++)
			for(int k = 0; k < m; k++)
			{
				if(!lot[a[j][k]])
				{
					reg[a[j][k]]++;
					break;
				}
			}
		int mp = 0, mr = -1;
		for(int j = 0; j < m; j++)
		{
			if(mp < reg[j])
			{
				mp = reg[j];
				mr = j;
			}
		}
		ret = min(ret, mp);
		lot[mr] = true;
	}
	cout << ret << endl;

	return 0;
}
