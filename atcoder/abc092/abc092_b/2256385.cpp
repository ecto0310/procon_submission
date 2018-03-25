// Date: Sun, 25 Mar 2018 12:09:29 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;


int A[100];

int main()
{
  int N,D,X;
  cin>> N>> D>> X;
  for(int i=0;i<N;i++)cin>> A[i];

  int ret=X;
  for(int i=0;i<N;i++)
  {
    ret+=D/A[i]+(D%A[i]?1:0);
  }
  cout<< ret<< endl;
  
  return 0;
}
