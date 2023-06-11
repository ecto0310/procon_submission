// Date: Sun, 11 Jun 2023 08:57:15 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using namespace chrono;
using i64 = int64_t;

const i64 END_TIME = 1800000;
const double START_TEMP = 2000;
const double END_TEMP = 100;

unsigned long xor128() {
  static unsigned long x = 123456789, y = 362436069, z = 521288629,
                       w = 88675123;
  unsigned long t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

double rand01() { return (xor128() + 0.5) * (1.0 / ULONG_MAX); }

struct Edge {
  int index, to, cost;
};

struct EdgeInfo {
  int u, v, cost;
};

struct Sender {
  int x, y;
  vector<Edge> edge;
};

struct House {
  int x, y;
  vector<Edge> edge;
};

struct Ans {
  int N, M;
  vector<int> P;
  vector<bool> B;

  Ans(int N, int M) : N(N), M(M), P(vector<int>(N)), B(vector<bool>(M)) {}

  void output() {
    for (int ind = 0; ind < N; ind++) {
      cout << P[ind] << " \n"[ind == N - 1];
    }
    for (int ind = 0; ind < M; ind++) {
      cout << (B[ind] ? 1 : 0) << " \n"[ind == M - 1];
    }
  }
};

i64 get_score(int N, int M, int K, vector<Sender> &senders,
              vector<EdgeInfo> &edge_infos, vector<House> &houses, Ans &ans) {
  vector<bool> use_senders(N), use_edges(M);
  queue<int> que;
  que.push(0);
  use_senders[0] = true;
  while (!que.empty()) {
    int p = que.front();
    que.pop();
    for (Edge edge : senders[p].edge) {
      if (!use_senders[edge.to] && ans.B[edge.index]) {
        que.push(edge.to);
        use_senders[edge.to] = true;
      }
    }
  }
  set<int> receive;
  for (int sender_ind = 0; sender_ind < N; sender_ind++) {
    if (use_senders[sender_ind]) {
      for (int house_ind = 0; house_ind < K; house_ind++) {
        double dist = hypot(senders[sender_ind].x - houses[house_ind].x,
                            senders[sender_ind].y - houses[house_ind].y);
        if (dist <= ans.P[sender_ind]) {
          receive.insert(house_ind);
        }
      }
    }
  }
  int n = receive.size();
  if (n == K) {
    i64 S = 0;
    for (int ind = 0; ind < N; ind++) {
      S += ans.P[ind] * ans.P[ind];
    }
    for (int ind = 0; ind < M; ind++) {
      if (ans.B[ind]) {
        S += edge_infos[ind].cost;
      }
    }
    return round(1e6 * (1 + 1e8 / (S + 1e7)));
  }
  return round(1e6 * ((double)(n + 1) / K));
}

i64 pre_score(int N, int M, int K, vector<Sender> &senders,
              vector<EdgeInfo> &edge_infos, vector<House> &houses, Ans &ans) {
  set<int> receive;
  for (int sender_ind = 0; sender_ind < N; sender_ind++) {
    if (ans.P[sender_ind]) {
      for (int house_ind = 0; house_ind < K; house_ind++) {
        double dist = hypot(senders[sender_ind].x - houses[house_ind].x,
                            senders[sender_ind].y - houses[house_ind].y);
        if (dist <= ans.P[sender_ind]) {
          receive.insert(house_ind);
        }
      }
    }
  }
  int n = receive.size();
  if (n == K) {
    i64 S = 0;
    for (int ind = 0; ind < N; ind++) {
      S += ans.P[ind] * ans.P[ind];
    }
    return round(1e6 * (1 + 1e8 / (S + 1e7)));
  }
  return round(1e6 * ((double)(n + 1) / K));
}

void init(int N, int M, int K, vector<Sender> &senders,
          vector<EdgeInfo> &edge_infos, vector<House> &houses, Ans &ans) {
  for (int ind = 0; ind < N; ind++) {
    ans.P[ind] = 2500;
  }
  for (int ind = 0; ind < M; ind++) {
    ans.B[ind] = true;
  }
}

void solve(int N, int M, int K, vector<Sender> &senders,
           vector<EdgeInfo> &edge_infos, vector<House> &houses,
           Ans &final_ans) {
  auto startClock = system_clock::now();
  init(N, M, K, senders, edge_infos, houses, final_ans);
  Ans ans = final_ans;
  i64 final_score = pre_score(N, M, K, senders, edge_infos, houses, final_ans);
  i64 score = final_score;
  double temp = START_TEMP;
  i64 loop = 0;
  for (;; loop++) {
    if (loop % 10 == 0) {
      i64 now_time =
          duration_cast<microseconds>(system_clock::now() - startClock).count();
      if (now_time >= END_TIME) {
        break;
      }
      temp =
          START_TEMP + (END_TEMP - START_TEMP) / ((double)now_time / END_TIME);
    }
    // if (0.5 < rand01()) {
    //   // いずれかの辺をON/OFFを反転
    //   int s = rand() % M;
    //   ans.B[s] = !ans.B[s];
    //   i64 tmp_score = pre_score(N, M, K, senders, edge_infos, houses, ans);
    //   double accept = exp((tmp_score - score) / temp);
    //   if (accept >= rand01()) {
    //     score = tmp_score;
    //     if (score > final_score) {
    //       final_ans = ans;
    //     }
    //   } else {
    //     ans.B[s] = !ans.B[s];
    //   }
    // } else
    {
      // いずれかの点のパワーを2500-x
      int s = xor128() % N;
      ans.P[s] = 2500 - ans.P[s];
      i64 tmp_score = pre_score(N, M, K, senders, edge_infos, houses, ans);
      double accept = exp((tmp_score - score) / temp);
      if (accept >= rand01()) {
        score = tmp_score;
        if (score > final_score) {
          final_ans = ans;
        }
      } else {
        ans.P[s] = 2500 - ans.P[s];
      }
    }
  }
  cerr << loop << " "
       << get_score(N, M, K, senders, edge_infos, houses, final_ans) << endl;
}

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<Sender> senders(N);
  for (Sender &i : senders) {
    cin >> i.x >> i.y;
  }
  vector<EdgeInfo> edge_infos(M);
  for (int ind = 0; ind < M; ind++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    edge_infos[ind] = {u, v, w};
    senders[u].edge.push_back({ind, v, w});
    senders[v].edge.push_back({ind, u, w});
  }
  vector<House> houses(K);
  for (House &i : houses) {
    cin >> i.x >> i.y;
  }
  Ans ans(N, M);
  solve(N, M, K, senders, edge_infos, houses, ans);
  ans.output();
  return 0;
}
