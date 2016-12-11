/**
 * TESTING: http://www.spoj.com/problems/RENT/
 * Correct Tested
 * Complexity: O(n*n)
 * Pseudocode: 
 * sort the jobs according to finish times in increasing order
 * for every job in dp -> choose job or don't choose job
 *Now apply following recursive process. 
 *  // Here arr[] is array of n jobs
 * findMaximumProfit(arr[], n)
 *  {
 *     a) if (n == 1) return arr[0];  // first job cannot start anythig before this
 *    b) Return the maximum of following two profits.
 *        (i) Maximum profit by excluding current job, i.e., 
 *            findMaximumProfit(arr, n-1)
 *        (ii) Maximum profit by including the current job            
 *  }
 * Proof: Simple DP no proof needed
 * Explanation: https://www.youtube.com/watch?v=cr6Ip0J9izc
 * 				http://www.geeksforgeeks.org/weighted-job-scheduling-log-n-time/
*/

/**
 * Assumptions
 * n>=1
 * Unweighted queries
 * Given start and end times -- no deadline case
 */

#include <iostream>
#include <algorithm>
#include <tuple>
#define MAX_ARR_SZ  10001

using namespace std;

tuple<int,int,int> time_profit_arr[MAX_ARR_SZ];  //start time, end time, profit
long long int max_profit_dp[MAX_ARR_SZ];


bool myComparator(tuple<int,int,long long int > x, tuple<int, int, long long int> y)
{	

	bool ret = get<1>(x) < get<1>(y);
	return ( ret );

}
//Initializes dp array with initial profits
void __initDp__(int n)
{
	for(int i=0;i<n;i++)
	{
		max_profit_dp[i]=  get<2>(time_profit_arr[i]);
	}	
}


void takeInput(int n)
{
		for(int i=0;i<n;i++)
	{
		int temp_start_time, duration,profit;
		cin>>temp_start_time;
		cin>>duration;
		cin>>profit;
		int temp_end_time =temp_start_time+duration;
		time_profit_arr[i]= make_tuple(temp_start_time,temp_end_time,profit);
	}
}


long long int solve(int n)
{
	__initDp__(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(get<1>(time_profit_arr[j]) <= get<0>(time_profit_arr[i]))  // if the finish time of j request <= start time of ith request  
			{
				max_profit_dp[i] = max(max_profit_dp[j]+ get<2>(time_profit_arr[i]), max_profit_dp[i]);
			}	
		}
	}
	long long int ans =0;
	for(int i=0;i<n;i++)
	{
		ans = max(max_profit_dp[i],ans);
	}
	return ans;

}


int main()
{

	ios_base::sync_with_stdio(false);
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		takeInput(n);
		sort(time_profit_arr,time_profit_arr+n,myComparator);

		cout<<solve(n)<<endl;


	}

return 0;

}