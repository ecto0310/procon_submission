// Date: Sun, 25 Jun 2023 09:39:19 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

const i64 N = 30;
const i64 BEAM_WIDTH = 5;

struct In {
  vector<vector<pair<i64, i64>>> b;
  i64 ball = N * (N + 1) / 2;
};

i64 get_step(i64 n) {
  for (i64 i = 0; i < N; i++) {
    if (n < (i + 1) * (i + 2) / 2) {
      return i;
    }
  }
  return N;
}

struct Ans {
  vector<i64> x, y, xd, yd, target_add;
  vector<vector<pair<i64, i64>>> b;
  i64 next_target = 0;
  i64 score;

  Ans(In in) : b(in.b) {}

  i64 getK() { return this->x.size(); }

  void push(i64 s_x, i64 s_y, i64 s_xd, i64 s_yd, i64 s_target_add) {
    cerr << s_x << " " << s_y << " " << s_xd << " " << s_yd << " "
         << s_target_add << endl;
    pair<i64, i64> t = this->b[s_xd][s_yd];
    this->b[s_xd][s_yd] = this->b[s_x][s_y];
    this->b[s_x][s_y] = t;
    this->next_target += s_target_add;
    this->update_score();
    this->x.push_back(s_x);
    this->y.push_back(s_y);
    this->xd.push_back(s_xd);
    this->yd.push_back(s_yd);
    this->target_add.push_back(s_target_add);
    return;
  }

  void pop() {
    i64 s_x = this->x.back();
    this->x.pop_back();
    i64 s_y = this->y.back();
    this->y.pop_back();
    i64 s_xd = this->xd.back();
    this->xd.pop_back();
    i64 s_yd = this->yd.back();
    this->yd.pop_back();
    i64 s_target_add = this->target_add.back();
    this->target_add.pop_back();
    pair<i64, i64> t = this->b[s_xd][s_yd];
    this->b[s_xd][s_yd] = this->b[s_x][s_y];
    this->b[s_x][s_y] = t;
    this->next_target -= s_target_add;
    this->update_score();
    return;
  }

  i64 calc_fullscore() {
    i64 E = 0;
    for (i64 i = 0; i < N - 1; i++) {
      for (i64 j = 0; j <= i; j++) {
        if (this->b[i][j] < this->b[i + 1][j] ||
            this->b[i][j] < this->b[i + 1][j + 1]) {
          E++;
        }
      }
    }
    cerr << E << endl;
    if (E != 0) {
      return 50000 - 50 * E;
    }
    return 100000 - 5 * this->getK();
  }

  vector<i64> putable_step(i64 s) {
    vector<i64> putable;
    for (i64 j = 0; j <= s; j++) {
      if (get_step(this->b[s][j].first) != s) {
        putable.push_back(j);
      }
    }
    return putable;
  }

  i64 update_score() {
    i64 score = 0;
    for (i64 i = 0; i < N - 1; i++) {
      for (i64 j = 0; j <= i; j++) {
        i64 step = get_step(this->b[i][j].first);
        score += (step - i) * (step - i);
      }
    }
    return this->score = score;
  }

  pair<i64, i64> get_pos(i64 n) {
    for (i64 i = 0; i < N; i++) {
      for (i64 j = 0; j <= i; j++) {
        if (this->b[i][j].first == n) {
          return {i, j};
        }
      }
    }
    return {-1, -1};
  }

  bool operator<(const Ans& ans) const { return this->score < ans.score; }

  friend ostream& operator<<(ostream& os, Ans& t) {
    i64 K = t.getK();
    os << K << endl;
    for (i64 i = 0; i < K; i++) {
      os << t.x[i] << " " << t.y[i] << " " << t.xd[i] << " " << t.yd[i] << endl;
    }
    return os;
  }
};

void solve(In& in, Ans& ans) {
  vector<priority_queue<Ans>> que(N);
  que[0].push(ans);
  for (i64 K = 0; K < 10000; K++) {
    cerr << K << " " << que[K % N].size() << endl;
    while (0 < que[K % N].size()) {
      cerr << "done" << que[K % N].size() << endl;
      Ans t = que[K % N].top();
      que[K % N].pop();
      cerr << "done?" << endl;
      while (t.get_pos(t.next_target).first < get_step(t.next_target) &&
             t.next_target < in.ball) {
        t.next_target++;
      }
      if (in.ball <= t.next_target) {
        ans = t;
        return;
      }
      auto [x, y] = t.get_pos(t.next_target);
      i64 step = (get_step(t.next_target) == x - 1 ? 1 : 0);
      if (step == -1) {
        vector<i64> putable = t.putable_step(x - 1);
        i64 ind =
            lower_bound(putable.begin(), putable.end(), y) - putable.begin();
        if (0 <= ind - 1 && abs(putable[ind - 1] - y) < abs(putable[ind] - y)) {
          ind--;
        }
        i64 target = putable[ind];
        cerr << "?:";
        for (i64 i : putable) {
          cerr << i << " ";
        }
        cerr << endl;
        if (y <= target) {
          while (y < target) {
            t.push(x, y, x, y + 1, 0);
            y++;
          }
          t.push(x, y, x - 1, y, 1);
        } else {
          while (target < y - 1) {
            t.push(x, y, x, y - 1, 0);
            y--;
          }
          t.push(x, y, x - 1, y - 1, 1);
        }
        i64 tK = t.getK();
        if (que[tK % N].size() <= BEAM_WIDTH ||
            que[tK % N].top().score < t.score) {
          que[tK % N].push(t);
          while (BEAM_WIDTH < que[tK % N].size()) {
            que[tK % N].pop();
          }
        }
        cerr << x << " " << y << " " << x - 1 << " " << target << " : " << tK
             << endl;
      } else {
        if (0 < y) {
          t.push(x, y, x - 1, y - 1, step);
          if (que[(K + 1) % N].size() <= BEAM_WIDTH ||
              que[(K + 1) % N].top().score < t.score) {
            que[(K + 1) % N].push(t);
          }
          t.pop();
        }
        if (y < x) {
          t.push(x, y, x - 1, y, step);
          if (que[(K + 1) % N].size() <= BEAM_WIDTH ||
              que[(K + 1) % N].top().score < t.score) {
            que[(K + 1) % N].push(t);
          }
          t.pop();
        }
        while (BEAM_WIDTH < que[(K + 1) % N].size()) {
          que[(K + 1) % N].pop();
        }
      }
    }
  }
  return;
}

void input(In& in) {
  for (i64 i = 1; i <= N; i++) {
    vector<pair<i64, i64>> b(i);
    for (i64 j = 0; j < i; j++) {
      cin >> b[j].first;
      b[j].second = get_step(b[j].first);
    }
    in.b.emplace_back(b);
  }
  return;
}

int main() {
  In in;
  input(in);
  Ans ans(in);
  solve(in, ans);
  cout << ans;
  cerr << ans.calc_fullscore() << endl;
  return 0;
}
