// Date: Mon, 12 Mar 2018 15:37:59 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  int d[100];
  cin>> N;
  for(int i=0;i<N;i++)cin>> d[i];

  set<int> s;
  for(int i=0;i<N;i++)
  {
    s.insert(d[i]);
  }
  cout<< s.size()<< endl;

  return 0;
}
