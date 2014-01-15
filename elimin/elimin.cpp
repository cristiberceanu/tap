#include <fstream>
#include <algorithm>
 
using namespace std;
 
ifstream f("elimin.in");
ofstream g("elimin.out");
  
int n, m, r, c, a[7000][17], st[7000], v[7000], s, sl[7000], sum[7000];
  
void citire()
{
    f>>m>>n>>r>>c;
     
    if(m>=n)
    {
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j)
            {
                f>>a[i][j];
                sl[i]+=a[i][j];
            }
    }
    else
    {
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j)
            {
                f>>a[j][i];
                sl[j]+=a[j][i];
            }
             
        swap(m,n);
        swap(r,c);
    }
}
  
void suma()
{
    int sol=0;
     
    for(int i=1;i<=m;++i)
    {
        sum[i]=sl[i];
         
        for( int j=1; j <= c; ++j)
            sum[i]-= a[i][st[j]];
    }
    sort(sum+1,sum+1+m);
  
    for(int i=r+1;i<=m;++i)
        sol += sum[i];
    if(sol>s)
        s=sol;
  
}
void bkt(int k)
{
    if(k==c+1)
    {
        suma();
        return;
    }
    for(int i = st[k-1]+1; i <= n; ++i)
    {
        st[k]=i;
        bkt(k+1);
    }
}
 
int main()
{
    citire();
    bkt(1);
    g<<s;
    return 0;
}