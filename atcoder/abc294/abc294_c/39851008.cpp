// Date: Sun, 19 Mar 2023 12:08:56 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 N, M;
  cin >> N >> M;
  vector<i64> A(N), B(M);
  for (i64 i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (i64 i = 0; i < M; i++) {
    cin >> B[i];
  }
  vector<i64> ansA(N), ansB(M);
  i64 now = 1, nowA = 0, nowB = 0;
  while (nowA != N || nowB != M) {
    i64 tA = (nowA == N ? 1e18 : A[nowA]);
    i64 tB = (nowB == M ? 1e18 : B[nowB]);
    if (tA < tB) {
      ansA[nowA] = now;
      nowA++;
    } else {
      ansB[nowB] = now;
      nowB++;
    }
    now++;
  }
  for (i64 i : ansA) {
    cout << i << " ";
  }
  cout << endl;
  for (i64 i : ansB) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
