#include <iostream>
//https://www.codechef.com/wiki/tutorial-just-simple-sum#Back_to_the_geometric_series

#define lli long long int 

lli M;

using namespace std;

lli powerx(lli a, lli n)
{

	if(n == 0)return 1;
	a%=M;
	//cout<<"a = "<<a<<endl;

	lli x = (powerx(a%M,n/2))%M;
	x%=M;
	lli y = (x*x)%M;
	if(n%2==0)
	{
		return y%M;
	}
	else 
	{
		return (y*a)%M;	
	}
}



lli fn(lli r, lli n)
{	


	if(n<=0)
	{
		return 1;
	}

	lli u = (fn((r*r)%M, (n-1)/2))%M;

	if(n%2==0)
	{
		return (((1+r)%M)*(u%M)) + powerx(r%M,n); 
	}	
	else
	{
		return  (((1+r)%M)*(u%M))%M;
	}


}







int NumDigits(lli x)  
{  
    return (x < 10LL ? 1 :   
        (x < 100LL ? 2 :   
        (x < 1000LL ? 3 :   
        (x < 10000LL ? 4 :   
        (x < 100000LL ? 5 :   
        (x < 1000000LL ? 6 :   
        (x < 10000000LL ? 7 :  
        (x < 100000000LL ? 8 :  
        (x < 1000000000LL ? 9 :  
        10)))))))));  
} 

int main()
{

	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		lli a,n,m;
		cin>>a>>n>>M;
		lli d  = NumDigits(a);
		lli r = powerx(10,d);
		//cout<<"r= "<<r<<endl;
		//cout<<"a mod M = "<<a%M<<endl;
		lli v = fn(r%M,n-1);
		cout<<((a%M)*(v%M))%M<<endl;

	}
	return 0;
}