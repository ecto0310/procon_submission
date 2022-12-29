// Date: Thu, 29 Dec 2022 12:55:50 +0000
// Language: C++17
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using ll = int64_t;

int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<pair<i64, i64>, i64>> d(n);
  for (i64 i = 0; i < n; i++) {
    cin >> d[i].first.second >> d[i].first.first;
    d[i].second = i;
  }
  sort(d.begin(), d.end());
  vector<i64> ans(n, -1);
  for (i64 i = 1; i <= 31; i++) {
    i64 cnt = 0;
    for (auto [d, ind] : d) {
      if (ans[ind] == -1 && cnt < k && d.second <= i) {
        cnt++;
        ans[ind] = i;
      }
    }
  }
  for (i64 i : ans) {
    cout << i << endl;
  }
}
