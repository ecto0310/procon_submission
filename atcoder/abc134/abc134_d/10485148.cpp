// Date: Mon, 02 Mar 2020 06:40:36 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 N;
  cin >> N;
  vector<i64> a(N);
  for (i64 i = 0; i < N; i++)
    cin >> a[i];
  vector<i64> ans;
  for (i64 i = N; 0 < i; i--)
  {
    for (i64 j = i * 2; j <= N; j += i)
      a[i - 1] = (a[i - 1] + a[j - 1]) % 2;
    if (a[i - 1] == 1)
      ans.push_back(i);
  }
  i64 size = ans.size();
  cout << size << endl;
  for (i64 i = 0; i < size; i++)
    cout << ans[i] << " \n"[i + 1 == size];
  return 0;
}
