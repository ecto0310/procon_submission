// Date: Tue, 13 Mar 2018 15:59:08 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int a[100000];

int main()
{
  int N;
  cin>> N;
  for(int i=0;i<N;i++)cin>> a[i];

  int ret=0;
  sort(a,a+N);
  for(int i=0;i<N;)
  {
    int now=a[i];
    int sum=0;
    for(;i<N;i++)
    {
      if(now==a[i])sum++;
      else break;
    }
    if(sum>=now)ret+=sum-now;
    else ret+=sum;
    cerr<< ":"<< now<< " "<< sum<< " "<< ret<< endl;
  }
  cout<< ret<< endl;

  return 0;
}
