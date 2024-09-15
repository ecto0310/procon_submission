// Date: Sun, 15 Sep 2024 13:03:18 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;
using namespace chrono;

const ll MXY = 1'000'000'000;
const ll TIME_LIMIT = 1900;

unsigned long xor128() {
  static unsigned long x = 123456789, y = 362436069, z = 521288629,
                       w = 88675123;
  unsigned long t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

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
  ll score = 0;
  vector<vector<ll>> to;

  void output() {
    cout << ops.size() << endl;
    for (Operate &op : ops) {
      cout << op.x << " " << op.y << " " << op.dx << " " << op.dy << endl;
    }
  }

  void add(ll x, ll y, ll dx, ll dy) {
    ops.push_back({x, y, dx, dy});
    score += abs(x - dx) + abs(y - dy);
  }
};

struct Edge {
  ll to, cost;
};

Ans solve(Input &input) {
  // point[input.N] = (0,0)
  input.sodas.push_back({0, 0});
  ll N = input.sodas.size();
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
  ans.to.resize(N);
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
      ans.to[from[now]].push_back(now);
      ans.add(fs.x, fs.y, ts.x, ts.y);
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
  auto start = system_clock::now();
  Input input;
  input.input();
  Ans ans = solve(input);
  set<ll> use;
  use.insert(input.N);
  while (true) {
    auto now = system_clock::now();
    double elapsed = duration_cast<milliseconds>(now - start).count();
    if (TIME_LIMIT < elapsed) {
      break;
    }
    ll idx = -1, tm = 0;
    for (ll i = 0; i < ans.to.size(); i++) {
      if (use.count(i) != 0) {
        continue;
      }
      if (tm < ans.to[i].size()) {
        tm = ans.to[i].size();
        idx = i;
      }
    }
    use.insert(idx);
    // cerr << idx << endl;
    Soda p = {MXY, MXY};
    for (ll i : ans.to[idx]) {
      p.x = min(p.x, input.sodas[i].x);
      p.y = min(p.y, input.sodas[i].y);
    }
    if (p.x == 0 && p.y == 0) {
      continue;
    }
    input.sodas.push_back(p);
    Ans tmp = solve(input);
    // cerr << p.x << " " << p.y << " " << ans.score - tmp.score << " "
    //      << ans.score << " " << tmp.score << endl;
    if (tmp.score < ans.score) {
      ans = tmp;
    } else {
      input.sodas.pop_back();
    }
  }
  ans.output();
}
