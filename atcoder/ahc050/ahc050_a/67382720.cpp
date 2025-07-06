// Date: Sun, 06 Jul 2025 10:45:31 +0000
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

vector<pair<ll, ll>> generate_checkerboard_pattern(const Input& input) {
  vector<pair<ll, ll>> positions;
  ll N = input.N;
  
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < N; ++j) {
      if (input.S[i][j] == '.' && (i + j) % 2 == 0) {
        positions.push_back({i, j});
      }
    }
  }
  
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < N; ++j) {
      if (input.S[i][j] == '.' && (i + j) % 2 == 1) {
        positions.push_back({i, j});
      }
    }
  }
  
  return positions;
}

// vector<pair<ll, ll>> generate_center_out_checkerboard(const Input& input) {
//   vector<pair<ll, ll>> positions;
//   ll N = input.N;
//   vector<vector<bool>> used(N, vector<bool>(N, false));
  
//   ll center = N / 2;
  
//   if (input.S[center][center] == '.') {
//     positions.push_back({center, center});
//     used[center][center] = true;
//   }
  
//   for (ll dist = 1; dist <= N; ++dist) {
//     for (ll i = 0; i < N; ++i) {
//       for (ll j = 0; j < N; ++j) {
//         ll manhattan_dist = abs(i - center) + abs(j - center);
//         if (manhattan_dist == dist && 
//             input.S[i][j] == '.' && !used[i][j]) {
//           positions.push_back({i, j});
//           used[i][j] = true;
//         }
//       }
//     }
//   }
  
//   return positions;
// }

Output solve(const Input& input) {
  Output output(input.N, input.M);
  
  vector<pair<ll, ll>> positions = generate_checkerboard_pattern(input);
  
  output.ans = positions;
  
  return output;
}

int main() {
  Input input;
  input.read();
  
  Output output = solve(input);
  output.write();
  
  return 0;
}
