// Date: Sat, 13 Apr 2019 10:44:49 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  int A[200];
  cin>> N;
  for(int i=0;i<N;i++)cin>> A[i];

  int ret=1000000000;
  for(int i=0;i<N;i++)
  {
    int cou=0;
    while(!(A[i]%2))
    {
      A[i]/=2;
      cou++;
    }
    ret=min(ret,cou);
  }
  cout<< ret<< endl;

  return 0;
}
