#include <fstream>
#define MAX 100005
using namespace std;

ifstream fin("scmax.in");
ofstream fout("scmax.out");

int v[MAX], best[MAX], prec[MAX], secv[MAX], seq_len, n;
int cautb(int x)
{
    int st, dr, m;
    st = 0;
    dr = seq_len;
    m = (st + dr)/2;
    while(st <= dr)
    {
        if(v[secv[m]] < x)
            st = m + 1;
        else 
            dr = m - 1;
        m = (st + dr) /2;
    }
    return m;
}

void afis(int poz)
{
    if(prec[poz]) afis(prec[poz]);
    fout<<v[poz]<<" ";
}

int main()
{
    int i;
    fin >> n;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    secv[1] = 1;
    seq_len = 1;
    for(i = 2; i <= n; i++){
        int poz = cautb(v[i]);
        prec[i] = secv[poz];
        secv[poz+1] = i;
        if(poz == seq_len) seq_len ++;
    }
    fout<<seq_len<<"\n";
    afis(secv[seq_len]);
    return 0;
}
