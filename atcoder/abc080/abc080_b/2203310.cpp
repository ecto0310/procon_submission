// Date: Wed, 14 Mar 2018 07:04:39 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin>> N;

  string ret="Yes";
  int sum=0;
  int num=N;
  while(num)
  {
    sum+=num%10;
    num/=10;
  }
  cerr <<":"<< sum<< endl;
  if(N%sum)ret="No";
  cout<< ret<< endl;

  return 0;
}
