#include <iostream>
#include <float.h>
#include <math.h>
#define INF DBL_MAX

double dist[101];
double arr[101][101];

using namespace std;

bool solve(int src, int n)
{
	for(int i=0;i<n;i++)
	{
		dist[i]=INF;
	}
		dist[src]=0;
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(dist[i]+arr[i][j]<dist[j])
					{
						dist[j]= dist[i] + arr[i][j];
					}
				}
			}
		}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(dist[i]+arr[i][j]<dist[j])
			{
				return true;
			}
		}
	}

	return false;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
		{
			int n;
			cin>>n;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					cin>>arr[i][j];
					arr[i][j] = -log(arr[i][j]);
				}
			}


			// for(int i=0;i<n;i++)
			// {
			// 	for(int j=0;j<n;j++)
			// 	{
			// 		arr[i][j] = -log(arr[i][j]);
			// 	}
			// }
			int flag  =1;
			// for(int i=0;i<=0;i++)
			// {
			// 	bool a = solve(i,n);
			// 	if(a==true)
			// 	{
			// 		cout<<"YES"<<endl;
			// 		flag =0;
			// 		break;
			// 	}
			// }
			// if(flag == 1)
			// {
			// 	cout<<"NO"<<endl;
			// }	
				bool a = solve(0,n);
				if(a==true)
				{
					cout<<"YES"<<endl;
				}
				else{
					cout<<"NO"<<endl;
				}


		}

	return 0;
}