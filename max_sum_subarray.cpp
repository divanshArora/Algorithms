//http://www.spoj.com/problems/MAXSUMSQ/

#include <iostream>
#define ll long long
#define INF 100000001
using namespace std;

ll arr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		ll pos_sum=0,neg_sum=0,ll global_max  = -INF;
		for(int i=0;i<n;i++)
		{
			if(arr[i]<0)
			{

				neg_sum+=arr[i];
				if(pos_sum+neg_sum>global_max)
				{
					global_max = pos_sum+neg_sum;
				}

			}


		}

	}
}
