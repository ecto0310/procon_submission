// Date: Wed, 03 Apr 2019 06:03:05 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n,k;
	string s;
	cin>>n>>k>>s;
	vector<int> cnt(26,0);
	for(int i=0;i<n;i++)
		cnt[s[i]-'a']++;
	string ans;
	for(int i=0;i<n;i++)
		for(int j=0;j<26;j++)
		{
			if(cnt[j]==0)
				continue;
			cnt[j]--;
			int dif=n-(s[i]==j+'a');
			for(int k=0;k<i;k++)
				dif-=(s[k]==ans[k]);
			vector<int> def(26,0);
			for(int k=i+1;k<n;k++)
				def[s[k]-'a']++;
			for(int i=0;i<26;i++)
				dif-=min(cnt[i],def[i]);
			if(dif<=k)
			{
				ans+=j+'a';
				break;
			}
			cnt[j]++;
		}
	cout<< ans<< endl;

	return 0;
}
