// Date: Sat, 24 Aug 2024 12:07:15 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, M, T, LA, LB;
  cin >> N >> M >> T >> LA >> LB;
  vector<vector<ll>> edge(N);
  for (ll i = 0; i < M; i++) {
    ll u, v;
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  T++;
  vector<ll> t(T);
  t[0] = 0;
  for (ll i = 1; i < T; i++) {
    cin >> t[i];
  }
  auto calc_path = [&]() -> pair<vector<ll>, vector<ll>> {
    vector<ll> all_path;
    map<vector<ll>, ll> count;
    for (ll i = 0; i < T - 1; i++) {
      ll start = t[i], goal = t[i + 1];
      priority_queue<pair<ll, ll>, std::vector<pair<ll, ll>>,
                     std::greater<pair<ll, ll>>>
          que;
      vector<ll> dist(N, 1e9);
      vector<ll> bef(N);
      que.push({0, start});
      dist[start] = 0;
      while (0 < que.size()) {
        auto [now_dist, now] = que.top();
        que.pop();
        if (dist[now] < now_dist) {
          continue;
        }
        for (ll to : edge[now]) {
          ll d = dist[now] + 1;
          if (d < dist[to]) {
            dist[to] = d;
            que.push({d, to});
            bef[to] = now;
          }
        }
      }
      vector<ll> path;
      for (ll now = goal; now != start; now = bef[now]) {
        path.push_back(now);
      }
      all_path.insert(all_path.end(), path.rbegin(), path.rend());
      path.push_back(start);
      reverse(path.begin(), path.end());
      for (ll left = 0; left < path.size(); left++) {
        for (ll length = 1; length <= LB && left + length - 1 < path.size();
             length++) {
          vector<ll> sub_path(path.begin() + left,
                              path.begin() + left + length);
          count[sub_path]++;
        }
      }
    }
    vector<priority_queue<pair<ll, vector<ll>>>> que(LB);
    for (auto [key, value] : count) {
      que[key.size() - 1].push({value, key});
    }
    set<vector<ll>> use_path;
    vector<bool> use(N);
    vector<ll> A;
    for (ll l = LB - 1; 0 <= l; l--) {
      priority_queue<pair<ll, vector<ll>>> tmp = que[l];
      while (0 < tmp.size()) {
        auto [c, v] = tmp.top();
        tmp.pop();
        bool ok = true;
        for (ll t : v) {
          if (use[t]) {
            ok = false;
          }
        }
        if (!ok) {
          continue;
        }
        use_path.insert(v);
        for (ll t : v) {
          if (A.size() < LA) {
            use[t] = true;
            A.push_back(t);
          }
        }
      }
    }

    for (ll l = LB - 1; 0 <= l && A.size() < LA; l--) {
      while (0 < que[l].size()) {
        auto [c, v] = que[l].top();
        que[l].pop();
        if (0 < use_path.count(v)) {
          continue;
        }
        for (ll t : v) {
          if (A.size() < LA) {
            A.push_back(t);
          }
        }
      }
    }
    return {A, all_path};
  };
  auto [A, all_path] = calc_path();
  for (ll i : A) {
    cout << i << " ";
  }
  cout << endl;
  vector<ll> B(LB, -1);
  auto is_blue = [&](ll v) -> bool {
    for (ll i : B) {
      if (i == v) {
        return true;
      }
    }
    return false;
  };
  auto is_equal = [&](ll path, ll a, ll length) -> bool {
    for (ll i = 0; i < length; i++) {
      if (A[a + i] != all_path[path + i]) {
        return false;
      }
    }
    return true;
  };
  for (ll i = 0; i < all_path.size(); i++) {
    if (!is_blue(all_path[i])) {
      bool op = false;
      for (ll length = LB; 0 < length && !op; length--) {
        for (ll a = 0; a < A.size() - length && !op; a++) {
          if (is_equal(i, a, length)) {
            cout << "s " << length << " " << a << " 0" << endl;
            for (ll t = 0; t < length; t++) {
              B[0 + t] = A[a + t];
            }
            op = true;
          }
        }
      }
    }
    cout << "m " << all_path[i] << endl;
  }
  return 0;
}
