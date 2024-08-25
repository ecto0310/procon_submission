// Date: Sun, 25 Aug 2024 11:29:29 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

struct Edge {
  ll to, cost;
};

struct Ans {
  vector<ll> A;
  vector<string> op;
  ll score = 0;

  void output() {
    for (ll i : A) {
      cout << i << " ";
    }
    cout << "\n";
    for (string &i : op) {
      cout << i << "\n";
    }
    cout << flush;
  }

  void add_move(ll v) { op.push_back("m " + to_string(v)); }

  void add_signal(ll length, ll a, ll b) {
    op.push_back("s " + to_string(length) + " " + to_string(a) + " " +
                 to_string(b));
    score++;
  }
};

struct Option {
  ll (*default_cost)(ll LB);
  ll (*update_cost)(ll cost, ll LB, ll T, ll target);
};

Ans solve(ll N, ll M, ll T, ll LA, ll LB, vector<pair<ll, ll>> &default_edge,
          vector<ll> &t, Option option) {
  Ans ans;
  vector<vector<Edge>> edge(N);
  ll default_cost = option.default_cost(LB);
  for (auto [u, v] : default_edge) {
    edge[u].push_back({v, default_cost});
    edge[v].push_back({u, default_cost});
  }
  auto calc_path = [&]() -> vector<ll> {
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
        for (auto [to, cost] : edge[now]) {
          ll d = dist[now] + cost;
          if (d < dist[to]) {
            dist[to] = d;
            que.push({d, to});
            bef[to] = now;
          }
        }
      }
      vector<ll> path;
      for (ll now = goal, last = -1; now != start; last = now, now = bef[now]) {
        path.push_back(now);
        if (last != -1) {
          for (auto &[to, cost] : edge[now]) {
            if (to == last) {
              cost = option.update_cost(cost, LB, T, i);
            }
          }
          for (auto &[to, cost] : edge[last]) {
            if (to == now) {
              cost = option.update_cost(cost, LB, T, i);
            }
          }
        }
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
        if (ans.A.size() < LA) {
          use[t] = true;
          ans.A.push_back(t);
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
        if (ans.A.size() < LA) {
          ans.A.push_back(t);
        }
      }
    }
    return all_path;
  };
  vector<ll> all_path = calc_path();
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
        if (all_path[path + i] == ans.A[a + j]) {
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
      for (ll length = 1; length <= LB; length++) {
        for (ll a = 0; a < ans.A.size() - length; a++) {
          ll t = is_equal(i, a, length);
          if (m < t) {
            s = {length, a};
            m = t;
          }
        }
      }
      auto [length, a] = s;
      if (LB <= b + length - 1) {
        b = 0;
      }
      ans.add_signal(length, a, b);
      for (ll t = 0; t < length; t++) {
        B[b + t] = ans.A[a + t];
      }
      b += length;
    }
    ans.add_move(all_path[i]);
  }
  return ans;
}

int main() {
  ll N, M, T, LA, LB;
  cin >> N >> M >> T >> LA >> LB;
  vector<pair<ll, ll>> default_edge(M);
  for (auto &[u, v] : default_edge) {
    cin >> u >> v;
  }
  T++;
  vector<ll> t(T);
  t[0] = 0;
  for (ll i = 1; i < T; i++) {
    cin >> t[i];
  }
  Option opt1 = {
      .default_cost = [](ll LB) -> ll { return 100; },
      .update_cost = [](ll cost, ll LB, ll T, ll target) -> ll { return 1; },
  };
  Ans ans1 = solve(N, M, T, LA, LB, default_edge, t, opt1);
  Option opt2 = {
      .default_cost = [](ll LB) -> ll { return 600 * LB; },
      .update_cost = [](ll cost, ll LB, ll T, ll target) -> ll {
        return max(cost / (2 * (T - target)), 1LL);
        ;
      },
  };
  Ans ans2 = solve(N, M, T, LA, LB, default_edge, t, opt2);
  if (ans1.score < ans2.score) {
    cout << "# select ans1" << endl;
    ans1.output();
  } else {
    cout << "# select ans2" << endl;
    ans2.output();
  }
}
