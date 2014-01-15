#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
 
using namespace std;
 
char a[1001][1001];
int m,n;
int dist[1001][1001];
int x0,y0,xf,yf;
 
ifstream fin("barbar.in");
ofstream fout("barbar.out");
 
vector< pair<int,int> > dragoni;
 
typedef struct{int x,y,dist;} nod;
 
bool operator<(nod x, nod y){
    return x.dist>y.dist;
}
 
 
bool viz[1001][1001];
int dirx[4] = {-1,0,+1,0};
int diry[4] = {0,+1,0,-1};
void dijkstra(){
    priority_queue< nod > q;
    nod x,y;
    for (std::vector< pair<int,int> >::iterator i = dragoni.begin(); i != dragoni.end(); ++i)
    {
            x.x = i->first; x.y = i->second; x.dist = 0;
            q.push(x);
    }
 
    do{
        x=q.top();
        q.pop();
        if(!viz[x.x][x.y]){
            viz[x.x][x.y] = true; dist[x.x][x.y] = x.dist;
            for (int i = 0; i < 4; ++i)
            {
                y.x = x.x + dirx[i]; y.y = x.y + diry[i];
                if(y.x >= 0 && y.x<m && y.y>=0 && y.y<n) 
                    if(!viz[y.x][y.y]){
                        y.dist = x.dist + 1;
                        q.push(y);
                    }
            }
        }
 
 
    }while(!q.empty());
}
 
int solve(){
    queue< pair<int,int> > q;
    vector< pair<int,int> > v;
    int step = dist[x0][y0];
    bool finished = false;
    v.push_back(make_pair(x0,y0));
    pair<int,int> cur,nod;
    for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                viz[i][j] = false;
            }
        }
    viz[x0][y0] = true;
    while(!finished && step>0){
        for (int it = 0; it<v.size(); ++it)
        {
            cur = v[it];
            // cout<<cur.first<<' '<<cur.second<<'\n';
            for (int i = 0; i < 4; ++i)
            {
                nod.first = cur.first + dirx[i];
                nod.second = cur.second + diry[i];
                if(nod.first >= 0 && nod.first<m && nod.second>=0 && nod.second<n){
                    if(!viz[nod.first][nod.second])
                        if(dist[nod.first][nod.second] >= step){
                        v.push_back(nod);
                         
                        // cout<<cur.first<<' '<<cur.second<<" => "<<nod.first<<" "<<nod.second<<"\n";
                        // for (std::vector< pair<int,int> >::iterator itx = v.begin(); itx != v.end(); ++itx)
                        //  {
                        //      cout<<itx->first<<' '<<itx->second<<", ";
                        //  }
                        // cout<<"\n";
 
                        viz[nod.first][nod.second] = true;
                        if(nod.first == xf && nod.second == yf){
                            return step;
                        }
                    }               
                } 
            }
        }
    step--;
    }
 
    return -1;
}
 
 
int main(int argc, char const *argv[])
{
    fin>>m>>n;
    for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                fin>>a[i][j];
                if(a[i][j]=='D') dragoni.push_back(make_pair(i,j));
                dist[i][j]=1<<20;
                if(a[i][j]=='I'){
                    x0 = i; y0 = j;
                }
                if(a[i][j]=='O'){
                    xf = i; yf = j;
                }
            }
        }   
 
 
            dijkstra();
            // for (int i = 0; i < m; ++i)
            // {
            //  for (int j = 0; j < n; ++j)
            //  {
            //      fout<<dist[i][j];
            //  }
            //  fout<<'\n';
            // }
 
            fout<<solve();
 
    return 0;
}