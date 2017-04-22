#include <iostream>
//http://www.spoj.com/problems/CLOPPAIR/

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	long long int n;
	cin>>n;
	vector< long long int > points(n+1);
	for(int i=0;i<n;i++)
	{
		long long int p;
		cin>>p;
		points.push_back(p);
	}
		


	return 0;
}