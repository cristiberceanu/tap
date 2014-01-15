#include <fstream>

using namespace std;

ifstream fin("flip.in");
ofstream fout("flip.out");

int a[20][20];
bool sign[20];
int n, m, sum = 0;

void solve() {
    int pmax, i, ii, j;
    pmax = 1 << m;
    for (i = 1; i < pmax; i++)
    {
        for (j = 0; j < m; j++) {
            if ((1 << j) & i)
                sign[j] = true;
            else
                sign[j] = false;
        }

        int tsum = 0;
        for (ii = 0; ii < n; ii++)
        {
            int lsum = 0;
            for (j = 0; j < m; j++)
            {
                if (sign[j])
                    lsum -= a[ii][j];
                else
                    lsum += a[ii][j];
            }
            if (lsum > 0)
                tsum += lsum;
            else
                tsum -= lsum;
        }
        if (tsum > sum)
            sum = tsum;

    }
}


int main() {
    int i, j;
    fin>>n; fin>>m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            fin>>a[i][j];
    solve();
    fout<<sum;
    }