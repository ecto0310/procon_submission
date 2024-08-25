// Date: Sun, 25 Aug 2024 06:03:47 +0000
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
    map<set<ll>, ll> count;
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
    }
    for (ll left = 0; left < all_path.size(); left++) {
      for (ll length = 1; length <= LB && left + length - 1 < all_path.size();
           length++) {
        set<ll> sub_path(all_path.begin() + left,
                         all_path.begin() + left + length);
        count[sub_path]++;
      }
    }
    priority_queue<pair<ll, set<ll>>> que;
    for (auto [key, value] : count) {
      que.push({value * (key.size() - 1), key});
    }
    set<set<ll>> use_path;
    vector<bool> use(N);
    vector<ll> A;
    priority_queue<pair<ll, set<ll>>> tmp = que;
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

    while (0 < que.size()) {
      auto [c, v] = que.top();
      que.pop();
      if (0 < use_path.count(v)) {
        continue;
      }
      for (ll t : v) {
        if (A.size() < LA) {
          A.push_back(t);
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
  auto is_equal = [&](ll path, ll a, ll length) -> ll {
    ll count = 0;
    for (ll i = 0; i < length; i++) {
      bool ok = false;
      for (ll j = 0; j < length; j++) {
        if (all_path[path + i] == A[a + j]) {
          count++;
          ok = true;
          break;
        }
      }
      if (!ok) {
        return count;
      }
    }
    return count;
  };
  ll b = 0;
  for (ll i = 0; i < all_path.size(); i++) {
    if (!is_blue(all_path[i])) {
      ll m = 0;
      pair<ll, ll> s;
      for (ll length = LB; 0 < length; length--) {
        for (ll a = 0; a < A.size() - length; a++) {
          ll t = is_equal(i, a, length);
          if (m < t) {
            s = {length, a};
            m = t;
          }
        }
      }
      auto [length, a] = s;
      if(LB<=b+length-1){
        b=0;
      }
      cout << "s " << length << " " << a << " " << b << endl;
      for (ll t = 0; t < length; t++) {
        B[b + t] = A[a + t];
      }
      b+=length;
    }
    cout << "m " << all_path[i] << endl;
  }
  return 0;
}
