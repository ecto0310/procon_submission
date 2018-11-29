// Date: Thu, 29 Nov 2018 16:33:41 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> edge(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	vector<int> p(n, 500);
	queue<int> que;
	p[0] = 0;
	que.push(0);
	while (que.size())
	{
		int q = que.front();
		que.pop();
		for (int i = 0; i < edge[q].size(); i++)
			if (p[q] + 1 < p[edge[q][i]])
			{
				p[edge[q][i]] = p[q] + 1;
				que.push(edge[q][i]);
			}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (p[i] < 3)
			ans++;
	cout << ans - 1 << endl;

	return 0;
}
