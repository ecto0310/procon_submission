// Date: Sun, 23 Sep 2018 03:26:06 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, a[100];
  cin >> n;
  for (int i = 0; i < n;i++){
    cin >> a[i];
  }
  int b=0, c=0, d=0;
  sort(a, a + n, greater<int>());
  for (int j = 0; j < n;j++){
    if(j%2==0){
      b = b + a[j];
    }else{
      c = c + a[j];
    }
  }
  cout << b - c << endl;
  return 0;
}
