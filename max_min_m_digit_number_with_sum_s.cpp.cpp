//http://codeforces.com/problemset/problem/489/C
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define S second
#define F first
#define INF 100000000000000000 //10^17
using namespace std;

int m,s;


int main()
{
	ios_base::sync_with_stdio(false);
	cin>>m>>s;
	int m1=m;
	string min="",max="";
	if(9*m<s || (s==0 && m>1))
	{
		cout<<"-1 -1";
		return 0;
	}
	if((s==0 && m==1))
	{
		cout<<"0 0";
		return 0;
	}
	int ncnt = s/9;
	for(int i=1;i<=ncnt;i++)
	{
		max+='9';
	}
	int temp = m - ncnt;
	if(temp>=1)
	{
		max+=to_string(s%9);
		temp--;
	}
	while(temp>0)
	{
		max+="0";
		temp--;
	}
	
	int i=1;
	m = m1;
	while(i<=m)
	{
		if(i==1)
		{
			for(int j=1;j<=9;j++)
			{
				if( (m-i)*9 + j >=s )
				{
					min+=to_string(j);
					s-=j;
					break;
				}
			}
		}
		else
		{	
			for(int j=0;j<=9;j++)
			{
				if( (m-i)*9 + j >=s )
				{
					min+=to_string(j);
					s-=j;
					break;
				}
			}
		}
		i++;
//		cout<<"min = "<<min<<endl;
	}
	cout<<min<<" "<<max;



}






