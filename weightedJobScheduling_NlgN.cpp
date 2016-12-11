/**
 * TESTING: http://www.spoj.com/problems/RENT/
 * Correct Tested
 * Complexity: O(n*lg(n))
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
 * Explanation: http://www.geeksforgeeks.org/weighted-job-scheduling-log-n-time/
 * ONLY DIFFERENCE b/w this and n*n:
 * use binary search to find the latest index for which start_time of j<= finish time of i 
 * and compare that with dp[i-1] and take maximum because at each step we are taking maximum till now in dp 
*/

/**
 * Assumptions
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

int myBinarySearch(int left_index, int right_index, int key)
{
	while(left_index<=right_index)
	{
		int mid= (left_index+ right_index)/2;
		int got_finish_time = get<1>(time_profit_arr[mid]);
		if( got_finish_time<=key )
		{

			if( mid+1<=right_index && get<1>(time_profit_arr[mid+1]) <= key )
			{
				left_index = mid + 1;
			}
			else
			{
				return mid;
			}
		}
		else if(got_finish_time>key)
		{
			right_index = mid-1;
		}

	}
	return -1;
}

long long int solve(int n)
{
	__initDp__(n);
	for(int i=1;i<n;i++)
	{
		int latestFinishedJob = myBinarySearch(0,i-1,get<0>(time_profit_arr[i]));
		if(latestFinishedJob!=-1){
			max_profit_dp[i] = max(max_profit_dp[latestFinishedJob]+ get<2>(time_profit_arr[i]), max_profit_dp[i]);
		}
		max_profit_dp[i] = max(max_profit_dp[i],max_profit_dp[i-1]);


	}
	long long int ans =0;
	
		ans = max_profit_dp[n-1];
	
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