// Date: Fri, 29 Nov 2024 13:29:42 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll xor128() {
  static ll x = 123456789, y = 362436069, z = 521288629, w = 88675123;
  ll t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

struct Ope {
  ll p, r;
  char d;
  ll b;
  bool set;
};

struct Ans {
  Ans(ll N, ll T, vector<pair<ll, ll>> &b) {
    opes.reserve(N);
    for (ll i = 0; i < N; i++) {
      opes.push_back(Ope{i, xor128() % 2, "UL"[xor128() % 2],
                         xor128() % (i + 1) - 1, true});
    }
  }
  vector<Ope> opes;

  void output() {
    ll n = 0;
    for (Ope i : opes) {
      if (i.set) {
        n++;
      }
    }
    cout << n << endl;
    for (Ope i : opes) {
      if (i.set) {
        cout << i.p << " " << i.r << " " << i.d << " " << i.b << endl;
      }
    }
  }

  ll score(ll w, ll h, vector<pair<ll, ll>> &b) {
    ll score = w + h;
    for (Ope i : opes) {
      if (!i.set) {
        score += b[i.p].first + b[i.p].second;
      }
    }
    cout << "#" << score << " = " << w << " + " << h << endl;
    return score;
  }

  ll get_score(vector<pair<ll, ll>> &b) {
    ll w, h;
    output();
    cin >> w >> h;
    return score(w, h, b);
  }

  void regen(ll N) {
    ll target = xor128() % N;
    opes[target] = Ope{target, xor128() % 2, "UL"[xor128() % 2],
                       xor128() % (target + 1) - 1, true};
  }
};

int main() {
  ll N, T, a;
  cin >> N >> T >> a;
  vector<pair<ll, ll>> b(N);
  for (pair<ll, ll> &i : b) {
    cin >> i.first >> i.second;
  }
  // Ans ans(N, T, b);
  // ll score = ans.get_score(b);
  for (ll i = 0; i < T; i++) {
    Ans ans(N, T, b);
    ll score = ans.get_score(b);
  }
}
