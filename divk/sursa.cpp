#include <iostream>
#include <fstream>
 
using namespace std;
 
long long sums[500010],results[100010];
 
int main()
{
    ifstream fin("divk.in");
    ofstream fout("divk.out");
    long long i,n,a,b,k,rez=0;
    fin>>n>>k>>a>>b;
    for(i=1;i<=n;i++)
    {
        fin>>sums[i];
        sums[i]+=sums[i-1];
        sums[i]=sums[i]%k;
    }
    for(i=a;i<=n;i++)
    {
        results[sums[i-a]]++;
        if(i>b)
            results[sums[i-b-1]]--;
        rez+=results[sums[i]];
    }

    fout<<rez;
    return 0;
}