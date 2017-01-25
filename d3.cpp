//Problem Link: http://www.spoj.com/problems/EZDIJKST/
//using set
//Correct tested works in set pair distance first
#include <iostream>
#include <set>
#include <vector>
#include <limits.h>
#define INFINITY INT_MAX

using namespace std;

//Custom comparator
struct mycomparator{
	bool operator()(const pair<int,int>&a, const pair<int,int>&b)
	{
		return a.second < b.second;
	}
};

// void printSet(set< pair< int, int> , mycomparator> &s  )
// {
// 	cout<<"SET = \n";
// 	for(auto it = s.begin();it!=s.end();it++)
// 	{
// 		cout<< (*(it)).first <<" "<<"dist = " << (*it).second<<" ";
// 	}
// 	cout<<endl;
// }

// void print_graph(vector < vector < pair <int , int > > > &graph, int n)
// {
// 	for(int i=0;i<n;i++)
// 	{
// 		cout<<i<<" --> ";
// 		int end = graph[i].size();
// 		for(int j=0;j<end;j++)
// 		{
// 			cout<<graph[i][j].first <<" w = " << graph[i][j].second ;
// 		}
// 		cout<<endl;
// 	}
// }

//Set implementation
void dijkstra(const vector< vector < pair< int , int> > > &graph, int n, int s, int d) // s= source n = V 
{
	set< pair<int,int> > activeVerices;	//initialiize set
	vector< int > dist(n,INFINITY); //initialize distance array
	dist[s]= 0; //source distance 0
	activeVerices.insert(make_pair(0,s));//insert source with distance 0
	while(!activeVerices.empty())
	{
		pair <int,int> current = *(activeVerices.begin());
		int a = current.second;
		activeVerices.erase(activeVerices.begin());
					//printSet(activeVerices);

		for(int i=0;i<graph[a].size();i++)
		{
			pair<int,int> next = graph[a][i];
			int b = next.first;
			int weight = next.second;
			//cout<<  " dist[current.first] + current.second  < dist[next.first] = "<<dist[current.first] << " "<< (graph[current.first][i]).second<<" " << dist[next.first]<<endl;  
			if(dist[a] + weight  < dist[b])
			{

				/*  If distance of v is not INF then it must be in
                    our set, so removing it and inserting again
                    with updated less distance.  
                    Note : We extract only those vertices from Set
                    for which distance is finalized. So for them, 
                    we would never reach here.  */
				if(dist[b]!=INFINITY)
				{
					auto it = activeVerices.find(make_pair(dist[b],b));
					activeVerices.erase(it);
				}
				dist[b] = dist[a] + weight;
				activeVerices.insert(make_pair(dist[b],b));
			}
		}

	}	
	if(dist[d]==INFINITY)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<< dist[d]<<endl;
		}
	return;
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
		vector< vector < pair< int , int> > > graph(n+1); //Weighted graph id,weight
		for(int i=0;i<e;i++)
		{
			int a,b,w;
			cin>>a>>b>>w;
			a--;b--;
			graph[a].push_back(make_pair(b,w));
		}
		int A,B;
		cin>>A>>B;
		A--;B--;
		//print_graph(graph,n);

		dijkstra(graph,n,A,B);	

		/*if(dist[B]==INFINITY)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<< dist[B]<<endl;
		}*/
	}


	return 0;
}
