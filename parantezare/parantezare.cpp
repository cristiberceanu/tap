#include<iostream>
#include<fstream>
using namespace std;
#define INF 100000000000000000LL
#define MAX 510
long long a[MAX][MAX], n, d[MAX];

long long min(long long x, long long y){
	if (x<y)
		return x;
	else
		return y;
}
int main(int argc, char const *argv[])
{
	ifstream f("podm.in");
	ofstream g("podm.out");
	f>>n;
	for (int i = 0; i <= n; ++i)
	{
		f>>d[i];		
	}

	for (int i = 1; i <= n; ++i)
	{
		a[i][i] = 0;
	}
	for (int i = 1; i <= n-1; ++i)
	{
		a[i][i+1] = d[i-1]*d[i]*d[i+1];
	}

	for (int k = 2; k <= n-1; ++k)
	{
		for (int i = 1; i <= n-k; ++i)
		{
			int j = i+k;
			a[i][j] = INF;
			for(int l=i; l<=j-1;l++)
				a[i][j] = min(a[i][j], a[i][l]+a[l+1][j]+d[i-1]*d[l]*d[j]);
		}

	}
	
	g<<a[1][n];
	return 0;
}