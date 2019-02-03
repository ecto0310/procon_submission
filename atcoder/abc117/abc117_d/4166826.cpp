// Date: Sun, 03 Feb 2019 13:49:16 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;

long a[100000];

int main()
{
  int N;
  long K;
  cin >> N >> K;
  int count[40] = {};
  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
    for (int j = 39; j >= 0; j--)
    {
      if (a[i] & (1L << j))
      {
        count[j]++;
      }
    }
  }
  long used = 0;
  int div = N / 2;
  bool isOdd = N % 2 == 1;
  for (int j = 39; j >= 0; j--)
  {
    if ((used + (1L << j)) <= K)
    {
      if (count[j] < N - count[j])
      {
        used += (1L << j);
      }
    }
  }
  long result = 0;
  for (int i = 0; i < N; i++)
  {
    result += used ^ a[i];
  }

  cout << result << endl;
  return 0;
}
