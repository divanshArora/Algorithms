/**
 * TESTING: http://www.spoj.com/problems/BUSYMAN/
 * Correct Tested
 * Pseudocode: Choose the job with least finish time
 * Proof: DIRVE
*/

/**
 * Assumptions
 * n>=1
 * Unweighted queries
 * Given start and end times -- no deadline case
 */

#include <iostream>
#include <algorithm>
#define MAX_ARR_SZ  100001

using namespace std;

pair<int,int> time_arr[MAX_ARR_SZ];


bool myComparator(pair<int,int> x, pair<int, int> y)
{	

	bool ret = x.second < y.second;
	return ( ret );

}




void takeInput(int n)
{
		for(int i=0;i<n;i++)
	{
		int temp_start_time, temp_end_time;
		cin>>temp_start_time;
		cin>>temp_end_time;
		time_arr[i]= make_pair(temp_start_time,temp_end_time);
	}


}



int main()
{

	ios_base::sync_with_stdio(false);
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		takeInput(n);
		sort(time_arr,time_arr+n,myComparator);
		
		long long int ans = 0;
		int current_max_finish_time = time_arr[0].second;  //initialied for base case
		ans++;
		for(int i=1;i<n;i++)
		{
			if(time_arr[i].first>=current_max_finish_time)  //if(start time of current request >= finish time of last request)
			{
				current_max_finish_time = time_arr[i].second;
				ans++;
			}
		}

		cout<<ans<<endl;


	}

return 0;

}