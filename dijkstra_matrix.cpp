//INCOMPLETE

#include <iostream>
#define N 101
#define MOD 100
#define INF 10001
#define NODE_DOESNT_EXIST -1

using namespace std;


int mat[N][N];

int dist[N]={INF};

bool visited[N]={false};

int dijkstra(int src, int n)
{	

	dist[src] = 0;
	for(int i=0;i<n;i++)
	{
		visited[i]= true;
		for(int j=0;j<n;j++)
		{
			int min = INF;
			int min_index;
			if(mat[i][j]!=NODE_DOESNT_EXIST && visited[j]==false && dist[j]<min) 
			{		
				min_index = j;
			}	
		}

		

	
	}



}




int main()
{
	
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
			cin>>arr[i];
	}
	for(int i=0;i<n;i++)dp[i][i]=0;
	for(int chain_length=2;chain_length<n;chain_length++)
	{
		//fill dp
		for(int i=0;i+chain_length-1<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if()
			}
		}
	}


	return 0;
}