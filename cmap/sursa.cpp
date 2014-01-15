#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <math.h>
  
using namespace std;
  
struct punct {long long x, y;} v[100005];
  
double minim(double x, double y) 
{
    if (x > y)
        return y;
    return x;
}
  
bool cmpx(punct a, punct b) { return a.x < b.x; }
  
bool cmpy(punct a, punct b) { return a.y < b.y; }
  
double dist(punct a, punct b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }
  
double dei(int st, int dr) 
{
    if (st >= dr)
        return 3000000000;
  
    if (st + 1 == dr)
        return dist(v[st], v[dr]);
  
    int m = (st + dr) / 2;
  
    double min = 3000000000;
  
    min = minim(min, dei(st, m));
    min = minim(min, dei(m + 1, dr));
  
    punct u[10100];
    int i, j, nr = 0, contor;
  
    for (i = st; i <= dr; ++i)
        if (abs(v[m].x - v[i].x) <= min)
            u[++nr] = v[i];
  
    sort(u + 1, u + nr + 1, cmpy);
  
    for (i = 1; i < nr; ++i)
        for (j = i + 1; j <= nr &&  (j - i) < 5; ++j)
            min = minim(min, dist(u[i], u[j]));
  
    return min;
}
  
int main() 
{
  
    ifstream fin("cmap.in");
    freopen("cmap.out", "w", stdout);
  
    int n;
    fin >> n;
  
    for (int i = 1; i <= n; ++i)
        fin >> v[i].x>>v[i].y;
  
    sort(v + 1, v + n + 1, cmpx);
  
    double dist = dei(1, n);
  
    printf("%.6lf\n", dist);
  
    return 0;
}