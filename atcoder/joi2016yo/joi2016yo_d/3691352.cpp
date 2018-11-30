// Date: Fri, 30 Nov 2018 16:15:51 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	long long n, t, q;
	cin >> n >> t >> q;
	vector<pair<long long, int>> data(n);
	for (int i = 0; i < n; i++)
		cin >> data[i].first >> data[i].second;
	vector<int> query(q);
	for (int i = 0; i < q; i++)
	{
		cin >> query[i];
		query[i]--;
	}
	vector<long long> stop;
	for (int i = 0; i < n; i++)
		if (data[i].second == 1 && data[i + 1].second == 2)
			stop.push_back((data[i].first + data[i + 1].first) / 2);
	int size = stop.size();
	for (int i = 0; i < q; i++)
	{
		int it = upper_bound(stop.begin(), stop.end(), data[query[i]].first) - stop.begin() - (data[query[i]].second == 2 ? 1 : 0);
		if (it == -1 || it == size || t < abs(stop[it] - data[query[i]].first))
			cout << data[query[i]].first + (data[query[i]].second == 1 ? 1 : -1) * t << endl;
		else
			cout << stop[it] << endl;
	}

	return 0;
}
