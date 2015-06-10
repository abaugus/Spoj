/*
	MATGAME.cpp
	Topic : Game Theory
	This problem can be solved by dividing the the game into subgames.
	Every row represent a subgame.Find out the grundy number for each row
	and perform nim sum to find out the winner.
*/
#include <bits/stdc++.h>
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define mp make_pair
#define ll long long
#define ull unsigned ll 
using namespace std;
int main()
{
	int t,i,j,n,m;
	scanf("%d",&t);
	while(t--)
	{	
		scanf("%d%d",&n,&m);
		int a[n][m+2],ans=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&a[i][j]);
			}	
		}
		for(i=0;i<n;i++)
		{
			int x=0;
			for(j=m-1;j>=0;--j)
			{
				x=(a[i][j]-1)+(a[i][j]-1>=x);
			}
			ans^=(x);	
		}
		if(ans)
			printf("FIRST\n");
		else
			printf("SECOND\n");
	}
	return 0;
}
