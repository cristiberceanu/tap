#include <vector>
#include<fstream>
#include <stdio.h>
using namespace std;
ifstream fin("tamplar.in");
FILE *f = fopen("tamplar.out", "w");
int d[7500], L;

int main()
{
    register int x, i, t, base = 100000;
    d[0] = 1;
    d[1] = 1;
    fin >> L;
    for ( x = 2;  x < L; ++x)
        {
            for( i = 1, t = 0; i <= d[0] || t; i++)
            {
                d[i] *= x;
                d[i] += t;
                t = d[i] / base;
                d[i] %= base;
            }

            d[0] = i - 1;

        }

    fprintf(f,"%d", d[ d[0]]);
    for( i = d[0] - 1; i >= 1; i--)
        fprintf(f,"%.5d", d[i]);
}
