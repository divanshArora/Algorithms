//Problem link: https://www.codechef.com/problems/STABLEMP
//Tested Gale-Shapley

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

//map<pair< int, int> > men_to_women,women_to_men;
int * stable_marriage(vector< vector < int > > & men_pref,vector< vector <int> > & women_pref, int n)
{

	queue<int> freemen;
	int * match_men = new int[n];
	int * match_women = new int[n];
	for(int i=0;i<n;i++)
	{
		freemen.push(i);
		match_women[i]=-1;
		match_men[i]=-1;
	}
	int women_matrix[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int myman = women_pref[i][j];
			women_matrix[i][myman] = j;
		}
	}
//	cout<<freemen.size();
	while(!freemen.empty())
	{
		int man = freemen.front();
		freemen.pop();
//		cout<<"MAN just popped = "<<man<<endl;
		for(int i=0;i<n && match_men[man]==-1;i++)
		{
//			cout<<"current man = "<<man<<endl;
			int woman = men_pref[man][i];
//			cout<<"Current preference "<<woman<<endl;
			if( match_women[woman]==-1 )
			{
//				cout<<"Woman was available"<<endl;
				match_women[woman] = man;
				match_men[man]=woman;
			}
			else 
			{
				int matched_man = match_women[woman];
//				cout<<"Women already engaged to "<<matched_man<<endl;
//				cout<<"Rank of our man = "<< women_matrix[woman][man]<<" other man = "<<women_matrix[woman][matched_man]<<endl;
				if( women_matrix[woman][man] < women_matrix[woman][matched_man])
				{
					match_women[woman] = man;
					match_men[man] = woman;
					freemen.push(matched_man);
					match_men[matched_man] = -1;					
				}
			}
		}

	}
	
	return match_men;

}





int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector< vector <int > > men_pref(n,vector<int>(n));
		vector< vector <int > >women_pref(n,vector<int>(n));
		for(int i=0;i<n;i++)
		{
			int g;cin>>g;
			for(int j=0;j<n;j++)
			{
				cin>>women_pref[i][j];
				women_pref[i][j]--;
			}
		}

		for(int i=0;i<n;i++)
		{
			int g;cin>>g;
			for(int j=0;j<n;j++)
			{
				cin>>men_pref[i][j];
				men_pref[i][j]--;
			}
		}
//		for(int i=0;i<n;i++)for(int j=0;j<n;j++)cout<<women_pref[i][j]<<" ";
		int * ans  =stable_marriage(men_pref,women_pref,n);
		for(int i=0;i<n;i++)
		{
			cout<<i+1<<" "<<ans[i]+1<<endl;
		}

	}

	return 0;
}