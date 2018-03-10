// Date: Sat, 10 Mar 2018 08:54:01 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N,K;
  cin>> N>> K;
  
  for(int i=0;i<K;i++)
  {
    if(N>K)cout<< N/2<< " "<< K<< endl;
    else cout<< "-1 -1"<< endl;
    i++;
    if(i>=K)break;
    if(N>K)cout<< K<< " "<< N/2<< endl;
    else cout<< "-1 -1"<< endl;
  }
  return 0;
}
