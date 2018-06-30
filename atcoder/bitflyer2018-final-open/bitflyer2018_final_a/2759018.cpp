// Date: Sat, 30 Jun 2018 05:25:28 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin>>n;
  int ans = 10;
  for (int i = 0; i < n;i++)
  {
    int p;
    cin >> p;
    int tmp = 0;
    while(p%10==0)
    {
      tmp++;
      p /= 10;
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;

  return 0;
}
