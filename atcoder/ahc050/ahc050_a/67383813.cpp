// Date: Sun, 06 Jul 2025 11:07:59 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

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
  
  Output(ll N, ll M) { 
    ans.reserve(N * N - M); 
  }
  
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
pair<ll, string> compute_score_details(const Input& input, const vector<pair<ll, ll>>& out) {
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
          while (i2 + di >= 0 && i2 + di < input.N && 
                 j2 + dj >= 0 && j2 + dj < input.N && 
                 S[i2 + di][j2 + dj] == '.') {
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
      return {0, "Position (" + to_string(bi) + ", " + to_string(bj) + ") is already blocked at turn " + to_string(t)};
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


vector<pair<ll, ll>> generate_greedy_pattern(const Input& input) {
  vector<pair<ll, ll>> positions;
  vector<string> S = input.S;
  vector<vector<double>> prob(input.N, vector<double>(input.N));
  
  for (ll i = 0; i < input.N; ++i) {
    for (ll j = 0; j < input.N; ++j) {
      if (input.S[i][j] == '.') {
        prob[i][j] = 1.0 / (input.N * input.N - input.M);
      }
    }
  }
  
  ll total_turns = input.N * input.N - input.M;
  
  for (ll turn = 0; turn < total_turns; ++turn) {
    double min_prob = 1.0;
    pair<ll, ll> best_pos = {-1, -1};
    
    for (ll i = 0; i < input.N; ++i) {
      for (ll j = 0; j < input.N; ++j) {
        if (S[i][j] == '.' && prob[i][j] < min_prob) {
          min_prob = prob[i][j];
          best_pos = {i, j};
        }
      }
    }
    
    if (best_pos.first != -1) {
      positions.push_back(best_pos);
      S[best_pos.first][best_pos.second] = '#';
      
      vector<vector<double>> next_prob(input.N, vector<double>(input.N, 0.0));
      
      for (ll i = 0; i < input.N; ++i) {
        for (ll j = 0; j < input.N; ++j) {
          if (prob[i][j] == 0.0) continue;

          vector<pair<ll, ll>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
          for (const auto& [di, dj] : dirs) {
            ll i2 = i, j2 = j;
            
            while (i2 + di >= 0 && i2 + di < input.N && 
                   j2 + dj >= 0 && j2 + dj < input.N && 
                   S[i2 + di][j2 + dj] == '.') {
              i2 += di;
              j2 += dj;
            }
            
            next_prob[i2][j2] += prob[i][j] * 0.25;
          }
        }
      }
      
      prob = next_prob;
    }
  }
  
  return positions;
}

Output solve(const Input& input) {
  Output output(input.N, input.M);
  
  output.ans = generate_greedy_pattern(input);
  
  return output;
}

int main() {
  Input input;
  input.read();
  
  Output output = solve(input);
  output.write();

  return 0;
}
