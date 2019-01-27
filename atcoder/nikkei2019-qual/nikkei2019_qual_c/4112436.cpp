// Date: Sun, 27 Jan 2019 16:44:50 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

struct Dish
{
  long long A, B;
};

int main()
{
  int N;
  cin >> N;
  vector<Dish> dish(N);
  for (int i = 0; i < N; i++)
    cin >> dish[i].A >> dish[i].B;
  sort(dish.begin(), dish.end(), [](const Dish &l, const Dish &r) { return (l.A + l.B > r.A + r.B); });
  long long ans = 0;
  for (int i = 0; i < N; i++)
    if (i % 2 == 0)
      ans += dish[i].A;
    else
      ans -= dish[i].B;
  cout << ans << endl;

  return 0;
}
