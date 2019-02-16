// Date: Sat, 16 Feb 2019 14:19:01 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  map<int, int> cnt;
  for (int i = 0; i < N; i++)
  {
    int K;
    cin >> K;
    for (int j = 0; j < K; j++)
    {
      int A;
      cin >> A;
      cnt[A]++;
    }
  }
  int ans = 0;
  for (pair<int, int> t : cnt)
    if (t.second == N)
      ans++;
  cout << ans << endl;

  return 0;
}
