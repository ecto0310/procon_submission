// Date: Wed, 03 Apr 2019 10:01:40 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	vector<long long> ans(n);
	for(int i=0;i<n;i++)
	{
		long long tmp=0;
		for(int j=i;j<n;j++)
		{
			tmp+=a[j];
			ans[j-i]=max(ans[j-i],tmp);
		}
	}
	for(long long i:ans)
		cout<<i<<endl;

	return 0;
}
