//http://codeforces.com/problemset/problem/580/C

#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

ll dist[200001]={0};
bool visited[200001]={false};
int cat[200001];
int catval[200001]={0};
ll ans= 0;
int m;
void dfs(int root, vector<vector<int> > &v, ll pd, int pid)
{
	//cout<<"root = "<<root<<endl;
	visited[root]=true;
	dist[root] = pd;
	if(cat[root]==1)
	{
		//cout<<root<<" has a cat"<<endl;
		if(pid!=-1)
		{
			catval[root]=catval[pid]+1;
		}	
		else catval[root]++;
	}
	int flag=0;
	
	for(int i=0;i<v[root].size();i++)
	{
		int u = v[root][i];
		if(visited[u]==false)
		{
			flag=1;
		}
	}
	//cout<<"catval of "<<root<<" = "<<catval[root]<<endl;
	if(catval[root]>m && flag!=0)
	{
		//cout<<"catval of "<<root<<" = "<<catval[root]<<" "<<endl;
		//cout<<"m = "<<m<<endl;
		return;
	}
	else if(flag==0 && catval[root]<=m)
	{
		//cout<<"adding to answer "<<root<<endl;
		ans++;
	}	

	for(int i=0;i<v[root].size();i++)
	{
		int u = v[root][i];
		if(visited[u]==false)
		{
			dfs(u,v,pd+1,root);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n>>m;
	vector< vector <int> > g(n+1);
	for(int i=0;i<n;i++)
	{
		cin>>cat[i];
	}

	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(0,g,0,-1);
	cout<<ans;
	return 0;
}





