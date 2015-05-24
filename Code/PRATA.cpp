#include <bits/stdc++.h>
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define ll long long
#define ull unsigned ll 
#define MAX 1005
using namespace std;
int a[MAX],n,p;
bool check(int time)
{
	int val=0;
	for(int i=0;i<n;i++)
	{
		val+=(-1+sqrt(1+(8*time)/a[i]))/2;
	}
	if(val>=p)
		return true;
	return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i;
		cin>>p;
		cin>>n;
		int r=0;
		rep(i,n)
		{
			cin>>a[i];
			r=max(r,a[i]);
		}	
		int hi=(r*p*(p+1))/2,lo=0,mid;
		while(lo<hi)
		{
			mid=(lo+hi)/2;
			if(check(mid))
				hi=mid;
			else
				lo=mid+1;
		}
		cout<<hi<<endl;
	}
	return 0;	
}
