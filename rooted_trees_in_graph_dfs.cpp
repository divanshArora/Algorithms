//http://codeforces.com/contest/115/problem/A

#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

ll dist[2001]={0};
bool visited[2001]={false};

void dfs(int root, vector<vector<int> > &v, ll pd)
{
	visited[root]=true;
	dist[root] = pd;
	for(int i=0;i<v[root].size();i++)
	{
		int u = v[root][i];
		if(visited[u]==false)
		{
			dfs(u,v,pd+1);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	vector< vector <int> > g(n+1);
	bool root[n];
	for(int i=0;i<n;i++)root[i]=false;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(x!=-1)
		{
			x--;
			g[x].pb(i);
		}
		else
		{
			root[i]=true;
		}
	}	
	for(int i=0;i<n;i++)
	{
		if(root[i]==true)
		{
			dfs(i,g,1);
		}
	}
	ll ans  =0;
	for(int i=0;i<n;i++)
	{
		ans = max(ans , dist[i]);
	}
	cout<<ans<<endl;

	return 0;
}





