#include <iostream>
#include <vector>

using namespace std;

void fn(vector<int> &v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i];
	}
}

int main()
{
	vector <int > v(20);
	fn(v);
}