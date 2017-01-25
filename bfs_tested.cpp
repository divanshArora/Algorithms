#include <iostream>
#include <vector>
#include <queue>

// https://www.hackerrank.com/challenges/bfsshortreach

using namespace std;

long long int dist[1001]={0};

int visited[1001]={0};
queue<int> mq;

void bfs(vector< vector< int > > &graph,int s)
{
	mq.push(s);
	dist[s]= 0;	
	visited[s]=true;
	while(!mq.empty())
	{
		int current  = mq.front();
		mq.pop();
		for(int i=0;i<graph[current].size();i++)
		{
			if(visited[ graph[current][i] ] == false)
			{
				mq.push(graph[current][i]);
				dist[graph[current][i]]=dist[current]+6;
				visited[graph[current][i]]=true;
			}
		}

	}
}

int main()
{

	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,e;
		cin>>n>>e;
		for(int i=0;i<n;i++){
			visited[i] = false;
			dist[i]=-1;
		}

		vector<vector< int > > graph(n+1);
		for(int i=0;i<e;i++)
		{
			int a,b;
			cin>>a>>b;
			a--;b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		int s;cin>>s;s--;
		bfs(graph,s);
		for(int i=0;i<n;i++)
		{
			if(i!=s)
			cout<<dist[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}