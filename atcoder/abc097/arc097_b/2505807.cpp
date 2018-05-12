// Date: Sat, 12 May 2018 15:08:03 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

struct UnionFind
{
	vector<int> data;

	UnionFind(int sz)
	{
		data.assign(sz, -1);
	}

	bool unite(int x, int y)
	{
		x = find(x), y = find(y);
		if(x == y) return(false);
		if(data[x] > data[y]) swap(x, y);
		data[x] += data[y];
		data[y] = x;
		return(true);
	}

	int find(int k)
	{
		if(data[k] < 0) return(k);
		return(data[k] = find(data[k]));
	}

	int size(int k)
	{
		return(-data[find(k)]);
	}
};

int p[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	UnionFind uf(n + 1);
	for(int i = 0; i < n; i++)cin >> p[i];
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		uf.unite(x-1, y-1);
	}
	int ret = 0;
	for(int i = 0; i < n; i++)
	{
		if(uf.find(p[i]-1) == uf.find(i))ret++;
	}
	cout << ret << endl;

	return 0;
}
