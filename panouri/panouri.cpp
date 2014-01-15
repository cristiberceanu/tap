#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("panouri.in");
ofstream fout("panouri.out");

int n,t;
int a[200001];
bool f[200001];
int v[200001];
int l,r;

bool verifica(int ln){
	int checked = 0;
	int l=0,r=ln-1;
	for (int i = 0; i < n; ++i)
	{
		v[i]=0;
	}
	for (int i = 0; i < ln; ++i)
	{
		if(f[a[i]]){
			if(!v[a[i]]) checked++;
			v[a[i]]++;	
		}
	}

	if(checked == t) return true;

	for (int i = ln; i < n; ++i)
	{
		if(f[a[l]]){
			v[a[l]]--;
			if(!v[a[l]]) checked--;
		}
		l++;
		r++;
		if(f[a[r]]){
			if(!v[a[r]]) checked++;
			v[a[i]]++;
		}

		if(checked == t) return true;
	}

	return false;
}

int main(int argc, char const *argv[])
{
	fin>>n>>t;
	for (int i = 0; i < n; ++i)
	{
		fin>>a[i];
	}
	for (int i = 0; i < t; ++i)
	{
		int x;
		fin >> x; f[x] = true;
	}

	//cautam binar lungimea solutiei
	int left = 1; int right = n;
	int solmin = 1<<20;
	while(left <= right){
		int mid = (left + right) / 2;
		// cout<<"( "<<left<<" "<<mid<<" "<<right<<")\n";
		if(verifica(mid)){
			// cout<<"Verifica lungimea "<<mid<<'\n';
			right = mid -1;
			if(mid < solmin) solmin = mid;
		}
		else{
			// cout<<"NU verifica lungimea "<<mid<<'\n';
			left = mid + 1;
		}

	}

	fout<<solmin-1;

	return 0;
}