#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

ifstream fin("biti.in");
ofstream fout("biti.out");

int a[100];
vector<int> sq;
int n, k=2;

void db(int t, int p){
	cout<<t<<' '<<p<<'\n';
	if(t > n)
	{

		if(n % p == 0)
			for (int j = 1; j < p + 1; ++j){
				sq.push_back(a[j]);
			}
	}
	else
	{
		a[t] = a[t - p];
		db(t + 1, p);
		for (int j = a[t-p] + 1; j < k; ++j)
		{
			a[t] = j;
			db(t + 1, t);
		}
	}

}

	int main(int argc, char const *argv[]){
		fin>>n;
		db(1,1);

		fout<<sq.size() + n - 1<<'\n';

		for (std::vector<int>::iterator i = sq.begin(); i != sq.end(); ++i){
			fout<<*i;
		}

		int ii = 1;
		for (std::vector<int>::iterator i = sq.begin(); ii < n && i != sq.end(); ++i, ++ii){
			fout<<*i;
		}

		return 0;
	}
