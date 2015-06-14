/*
	DCEPC706.cpp
	Topic : BFS  
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
#define MAX 205
using namespace std;
char s[MAX][MAX],e[MAX];
int a[MAX][MAX][3],n,m;
bool visited[MAX][MAX][3];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void bfs(int x,int y,int d)
{
	queue<int > quex,quey;
	int topx,topy,dist=0;
	visited[x][y][d]=1;
	a[x][y][d]=dist;
	quex.push(x);
	quey.push(y);
	while(!quex.empty())
	{
		topx=quex.front();
		topy=quey.front();
		quex.pop();
		quey.pop();
		dist=a[topx][topy][d];
		for(int i=0;i<4;i++)
		{
			x=topx+dx[i];
			y=topy+dy[i];
			if(x>=0 && x<=n-1 && y>=0 && y<=m-1)
			{
				if(visited[x][y][d]==false)
				{
					visited[x][y][d]=1;
					if(s[x][y]=='#')
					{
						a[x][y][d]=INT_MAX;
					}	
					else
					{
						quex.push(x);
						quey.push(y);
						a[x][y][d]=dist+1;
					}
				}
			}
		}
	}
}
int main()
{
	int t,i,j,k,l;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(visited,0,sizeof(visited));
		cin>>n>>m;
		n+=2;
		m+=2;
		for(j=0;j<m;j++)
		{
			s[0][j]='.';
			s[n-1][j]='.';
		}
		for(i=1;i<n-1;i++)
		{
			cin>>e;
			s[i][0]='.';
			for(j=1;j<m-1;j++)
			{
				s[i][j]=e[j-1];
			}
			s[i][m-1]='.';
		}	
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(s[i][j]=='1')
				{
					bfs(i,j,0);
				}
				else if(s[i][j]=='2')
				{
					bfs(i,j,1);
				}
				else if(s[i][j]=='3')
				{
					bfs(i,j,2);
				}
			}
		}
		int ans=99999999,val;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				val=max(a[i][j][0],max(a[i][j][1],a[i][j][2]));
				if(val!=INT_MAX)
					ans=min(val,ans);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
