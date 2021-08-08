// Date: Sun, 08 Aug 2021 13:03:51 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  	int M, S, T, L;
  	cin >> M >> S >> T >> L;
  	int t;
  	for(int i=0; i<S*(M+1);i++){
      	cin >> t;
    }
  	int K=0;
  	vector<int> n(M);
  	for(int i=0; i<M ;i++) {
      	cin >> n[i];
      	K+=n[i];
    }
  	cout << K << endl;
    while(true){
    	bool u=false;
  		for(int i=0; i<M ;i++) {
          	if(n[i]!=0){
            	cout<< i+1 << " ";
              	n[i]--;
            	u=true;
          	}
    	}
      	if(!u){
         	cout<<endl;
         	break;
        }
    }
	return 0;
}
