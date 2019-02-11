// Date: Mon, 11 Feb 2019 11:47:39 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

const int timeLimit = 1998;

int N;
vector<pair<int, int>> T;

vector<int> ans;

unsigned int randxor()
{
  static unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
  unsigned int t;
  t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

void input()
{
  cin >> N;
  T.resize(N);
  for (int i = 0; i < N; i++)
    cin >> T[i].first >> T[i].second;
}

void init()
{
  ans.resize(N);
  for (int i = 0; i < N; i++)
    ans[i] = i;
}

int eval(vector<int> &order)
{
  double average = 0;
  vector<double> d(N);
  for (int i = 0; i < N; i++)
  {
    double x = abs(T[order[i]].first - T[order[(i - 1 == -1 ? N - 1 : i - 1)]].first), y = abs(T[order[i]].second - T[order[(i - 1 == -1 ? N - 1 : i - 1)]].second);
    d[i] = sqrt(pow(x, 2) + pow(y, 2));
    average += d[i];
  }
  average /= N;
  double ret = 0;
  for (int i = 0; i < N; i++)
    ret += pow(d[i] - average, 2);
  ret /= N;
  return ceil(1e6 / (1 + ret));
}

void simulate()
{
  chrono::system_clock::time_point start = chrono::system_clock::now();
  int loopCount = 0, bestScore = eval(ans);
  while (chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - start).count() / 1000 < timeLimit)
  {
    int s[2] = {randxor() % (N - 1), randxor() % (N - 1)};
    swap(ans[s[0]], ans[s[1]]);
    int tmpScore = eval(ans);
    if (bestScore < tmpScore)
      bestScore = tmpScore;
    else
      swap(ans[s[0]], ans[s[1]]);
    loopCount++;
  }
  cerr << "loop:" << loopCount << endl
       << "score:" << bestScore << endl;
}

void output()
{
  for (int t : ans)
    cout << t << endl;
}

int main()
{
  input();
  init();
  simulate();
  output();

  return 0;
}
