// Date: Sat, 08 Jun 2024 17:26:38 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> h(n);
  for(auto&i:h)cin>>i;
  for(int i=0;i<n;i++){
    if(m<h[i]){
      cout<<i<<endl;
      return 0;
    }
    m-=h[i];
  }
  cout<<n<<endl;
}
