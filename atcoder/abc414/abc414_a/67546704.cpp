// Date: Sat, 12 Jul 2025 13:02:53 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N,L,R;
  cin >> N >> L >> R;
  ll ans =0;
  for(ll i=0;i<N;i++){
    ll X,Y;
    cin >> X >> Y;
    if(X<=L && Y>=R){
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
