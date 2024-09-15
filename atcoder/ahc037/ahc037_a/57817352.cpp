// Date: Sun, 15 Sep 2024 12:10:15 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;
using namespace chrono;

struct Soda {
  ll x, y;

  pair<bool, ll> dist(Soda &to) {
    if (x <= to.x && y <= to.y) {
      return {true, abs(x - to.x) + abs(y - to.y)};
    }
    return {false, 0};
  }
};

struct Input {
  ll N;
  vector<Soda> sodas;

  void input() {
    cin >> N;
    sodas.resize(N);
    for (Soda &soda : sodas) {
      cin >> soda.x >> soda.y;
    }
  }
};

struct Operate {
  ll x, y, dx, dy;
};

struct Ans {
  vector<Operate> ops;

  void output() {
    cout << ops.size() << endl;
    for (Operate &op : ops) {
      cout << op.x << " " << op.y << " " << op.dx << " " << op.dy << endl;
    }
  }
};

struct Edge {
  ll to, cost;
};

Ans solve(Input &input) {
  // point[input.N] = (0,0)
  input.sodas.push_back({0, 0});
  ll N = input.N + 1;
  vector<vector<Edge>> edges(N);
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) {
      if (i == j) {
        continue;
      }
      // i -> j
      auto [ok, dist] = input.sodas[i].dist(input.sodas[j]);
      if (ok) {
        edges[i].push_back({j, dist});
        // cerr << i << " -> " << j << " " << dist << endl;
      }
    }
  }
  vector<ll> dists(N, 1e18);
  vector<ll> from(N, -1);
  vector<bool> use(N, false);
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
  dists[N - 1] = 0;
  que.push({0, N - 1});
  Ans ans;
  while (0 < que.size()) {
    auto [d, now] = que.top();
    que.pop();
    if (use[now]) {
      continue;
    }
    use[now] = true;
    if (from[now] != -1) {
      Soda fs = input.sodas[from[now]];
      Soda ts = input.sodas[now];
      ans.ops.push_back({fs.x, fs.y, ts.x, ts.y});
    }
    // cerr << now << " " << d << " " << edges[now].size() << endl;
    for (auto [to, cost] : edges[now]) {
      ll w = dists[now] + cost;
      // cerr << "  " << to << " " << w << endl;
      if (dists[to] < w) {
        continue;
      }
      // cerr << "update" << endl;
      dists[to] = w;
      from[to] = now;
      que.push({dists[to], to});
    }
  }
  return ans;
}

int main() {
  // auto startClock = system_clock::now();
  Input input;
  input.input();
  Ans ans = solve(input);
  ans.output();
}
