// Date: Sun, 06 Jul 2025 12:05:40 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

#include <random>

using ll = long long;
using namespace std;

struct Input {
  ll N, M;
  vector<string> S;

  Input() {}

  void read() {
    cin >> N >> M;
    S.resize(N);
    for (ll i = 0; i < N; ++i) {
      cin >> S[i];
    }
  }
};

struct Output {
  vector<pair<ll, ll>> ans;

  Output(ll N, ll M) { ans.reserve(N * N - M); }

  void write() {
    for (const auto& p : ans) {
      cout << p.first << " " << p.second << endl;
    }
  }
};

// 評価関数の構造体
struct State {
  vector<vector<char>> S;
  vector<vector<double>> prob;
  vector<double> lives;
};

// 評価関数の詳細実装
pair<ll, string> compute_score_details(const Input& input,
                                       const vector<pair<ll, ll>>& out) {
  vector<string> S = input.S;
  vector<vector<double>> crt(input.N, vector<double>(input.N, 0.0));

  // 初期確率分布を設定
  for (ll i = 0; i < input.N; ++i) {
    for (ll j = 0; j < input.N; ++j) {
      if (input.S[i][j] == '.') {
        crt[i][j] = 1.0 / (input.N * input.N - input.M);
      }
    }
  }

  double ret = 0.0;
  vector<double> lives = {1.0};
  double life = 1.0;

  // 各ターンでシミュレーション
  for (ll t = 0; t < (ll)out.size(); ++t) {
    // ロボットの移動後の確率分布を計算
    vector<vector<double>> next(input.N, vector<double>(input.N, 0.0));

    for (ll i = 0; i < input.N; ++i) {
      for (ll j = 0; j < input.N; ++j) {
        if (crt[i][j] == 0.0) continue;

        // 4方向に移動（Rustの実装に合わせる）
        // Rustでは [(!0, 0), (1, 0), (0, !0), (0, 1)] を使用
        vector<pair<ll, ll>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto& [di, dj] : dirs) {
          ll i2 = i, j2 = j;

          // 岩にぶつかるまで移動
          while (i2 + di >= 0 && i2 + di < input.N && j2 + dj >= 0 &&
                 j2 + dj < input.N && S[i2 + di][j2 + dj] == '.') {
            i2 += di;
            j2 += dj;
          }

          next[i2][j2] += crt[i][j] * 0.25;
        }
      }
    }

    crt = next;

    // 岩を配置
    ll bi = out[t].first, bj = out[t].second;

    // 既に岩がある場合はエラー
    if (S[bi][bj] == '#') {
      return {0, "Position (" + to_string(bi) + ", " + to_string(bj) +
                     ") is already blocked at turn " + to_string(t)};
    }

    // ロボットが潰される確率を減算
    life -= crt[bi][bj];
    crt[bi][bj] = 0.0;
    S[bi][bj] = '#';

    ret += life;
    lives.push_back(life);
  }

  // スコア計算
  double ub = (input.N * input.N - input.M - 1);
  ll score = (ll)((ret / ub) * 1e6 + 0.5);

  string err = "";
  if (out.size() < input.N * input.N - input.M) {
    err = "Not finished";
  }

  return {score, err};
}

// メインの評価関数
pair<ll, string> compute_score(const Input& input, const Output& output) {
  auto [score, err] = compute_score_details(input, output.ans);
  if (!err.empty()) {
    score = 0;
  }
  return {score, err};
}

struct BeamState {
  vector<pair<ll, ll>> positions;
  vector<string> S;
  vector<vector<double>> prob;
  double score;

  BeamState() : score(0.0) {}

  BeamState(const Input& input) {
    S = input.S;
    prob.resize(input.N, vector<double>(input.N));
    score = 0.0;

    for (ll i = 0; i < input.N; ++i) {
      for (ll j = 0; j < input.N; ++j) {
        if (input.S[i][j] == '.') {
          prob[i][j] = 1.0 / (input.N * input.N - input.M);
        }
      }
    }
  }

  BeamState(const BeamState& other) {
    positions = other.positions;
    S = other.S;
    prob = other.prob;
    score = other.score;
  }

  void place_rock(ll i, ll j) {
    positions.push_back({i, j});
    S[i][j] = '#';

    score += (1.0 - prob[i][j]);

    vector<vector<double>> next_prob(S.size(), vector<double>(S.size(), 0.0));

    for (ll x = 0; x < (ll)S.size(); ++x) {
      for (ll y = 0; y < (ll)S.size(); ++y) {
        if (prob[x][y] == 0.0) continue;

        vector<pair<ll, ll>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto& [dx, dy] : dirs) {
          ll x2 = x, y2 = y;

          while (x2 + dx >= 0 && x2 + dx < (ll)S.size() && y2 + dy >= 0 &&
                 y2 + dy < (ll)S.size() && S[x2 + dx][y2 + dy] == '.') {
            x2 += dx;
            y2 += dy;
          }

          next_prob[x2][y2] += prob[x][y] * 0.25;
        }
      }
    }

    prob = next_prob;
  }
};

vector<pair<ll, ll>> generate_beam_search_pattern(const Input& input) {
  const ll BEAM_WIDTH = 5;
  const ll TRY_NUM = 6;
  vector<BeamState> beam;
  beam.emplace_back(input);

  ll total_turns = input.N * input.N - input.M;

  for (ll turn = 0; turn < total_turns; ++turn) {
    vector<BeamState> next_beam;

    for (const auto& state : beam) {
      double min_prob = 1.0;
      vector<pair<ll, ll>> candidates;

      for (ll i = 0; i < input.N; ++i) {
        for (ll j = 0; j < input.N; ++j) {
          if (state.S[i][j] == '.' && state.prob[i][j] <= min_prob) {
            if (state.prob[i][j] < min_prob) {
              min_prob = state.prob[i][j];
              candidates.clear();
            }
            candidates.push_back({i, j});
          }
        }
      }

      if (!candidates.empty()) {
        random_device rd;
        mt19937 gen(rd());

        ll num_to_select = min(TRY_NUM, (ll)candidates.size());

        vector<pair<ll, ll>> shuffled_candidates = candidates;
        shuffle(shuffled_candidates.begin(), shuffled_candidates.end(), gen);

        for (ll i = 0; i < num_to_select; ++i) {
          BeamState new_state = state;
          new_state.place_rock(shuffled_candidates[i].first,
                               shuffled_candidates[i].second);
          next_beam.push_back(new_state);
        }
      }
    }

    sort(next_beam.begin(), next_beam.end(),
         [](const BeamState& a, const BeamState& b) {
           return a.score > b.score;
         });

    if (next_beam.size() > BEAM_WIDTH) {
      next_beam.erase(next_beam.begin() + BEAM_WIDTH, next_beam.end());
    }

    beam = next_beam;
  }

  if (!beam.empty()) {
    return beam[0].positions;
  }

  return {};
}

Output solve(const Input& input) {
  Output output(input.N, input.M);

  output.ans = generate_beam_search_pattern(input);

  return output;
}

int main() {
  Input input;
  input.read();

  Output output = solve(input);
  output.write();

  return 0;
}
