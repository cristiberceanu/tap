#include <iostream>
#include<fstream>
#include<algorithm>
#include<string.h>

using namespace std;

class Betiv
{
public:
	int first , second , indice;
	Betiv(int first , int second , int indice)
	{
		this->first = first;
		this->second = second;
		this->indice = indice;
	}
	Betiv()
	{
		first = 0;
		second = 0;
		indice = 0;
	}
};

int n,l;
int timp_ramas[173];
Betiv timpi[173];
Betiv sol[173];
Betiv sol_min[173];
int tmin=1000;


bool cmp(const Betiv & p1, const Betiv & p2)
{
	/*double r1=(double)p1.first/(double)p1.second;
	double r2=(double)p2.first/(double)p2.second;
 
	return r1<r2;*/
	return (p1.first - p1.second) < (p2.first - p2.second);
}
bool cmp2(const Betiv & p1, const Betiv & p2)
{
	return p1.indice < p2.indice;
}

int main()
{
	ifstream input("lapte.in");
	ofstream output("lapte.out");
	
	input>>n>>l;
	
	for(int i=0; i<n; i++)
	{
		input>>timpi[i].first>>timpi[i].second;
		timpi[i].indice = i;
	}
	
	sort(timpi, timpi+n,cmp);
	int left=0, right=100;
	
	while (left<=right)
	{
		int m=(left+right)/2;
		
		for (int i = 0; i < n ; i++)
		{
			timp_ramas[i] = m;
			sol[i] = Betiv(0,0,timpi[i].indice);
		}
		int lapteA=l;
		int lapteB=l;
		
		for(int i=0; i<n && lapteA>0; i++)
		{
			int lapte=m/timpi[i].first;
			if (lapte<=lapteA)
			{
				lapteA-=lapte;
				timp_ramas[i]=0;
				sol[i].first += lapte;
			}
			else
			{
				timp_ramas[i]-=lapteA*timpi[i].first;
				sol[i].first += lapteA;
				lapteA = 0;
			}
			
		}
		
		for (int i=n-1; i>=0 && lapteB>0; i--)
		{
			int lapte=timp_ramas[i]/timpi[i].second;
			if (lapte<=lapteB)
			{
				lapteB-=lapte;
				timp_ramas[i]=0;
				sol[i].second += lapte;
			}
			else
			{
				timp_ramas[i]-=lapteB*timpi[i].second;
				sol[i].second+=lapteB;
				lapteB = 0;
			}
		}
		if (lapteA!=0 || lapteB!=0)
			left=m+1;
		else
		{
			if (m<tmin)
			{
				tmin=m;
				for (int i=0;i<n;i++)
					sol_min[i]=sol[i];
			}
			right=m-1;
		}
		
	}
	output << tmin << endl;
	sort(sol_min,sol_min + n , cmp2);
	for (int i=0; i<n; i++)
	{
		output<<sol_min[i].first<<" "<<sol_min[i].second<< endl;
	}
	
	return 0;
}