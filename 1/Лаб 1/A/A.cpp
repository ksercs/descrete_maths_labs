#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <string.h>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const int MAXSZ = 2*15+2, MAXN = 15;

int n, m, ans;
VEC < PII > f;
int gr[MAXSZ][MAXSZ];
int u[MAXSZ];

void DFS(int v){
    if(!u[v+MAXN]){
        u[v+MAXN] = 1;
        for(int i = -MAXN; i <= MAXN; i++){
            if(gr[v+MAXN][i+MAXN]){
                DFS(i);
                for(int j = -MAXN; j <= MAXN; j++)
                    if(gr[i+MAXN][j+MAXN])
                        gr[v+MAXN][j+MAXN] = 1;
            }
        }
    }
}

void in()
{
    //ifstream cin("A.in");
    cin >> n >> m;
    f.resize(m);
    for (int i = 0; i < m; ++i)
        cin >> f[i].FF >> f[i].SS;
}

void solution()
{
    for (int i = 0; i < m; ++i){
        gr[-f[i].FF+MAXN][f[i].SS+MAXN] = 1;
        gr[-f[i].SS+MAXN][f[i].FF+MAXN] = 1;
    }
    for(int i = -MAXN; i <= MAXN; i++){
        DFS(i);
        memset(u, 0, sizeof(u));
    }
    int ind = 0;
    for(int n = MAXN; n - ind > 0; --n){
		int a = ind - n;
		int b = n - ind;
        if ( gr[a+MAXN][b+MAXN] && gr[b+MAXN][a+MAXN] ){
            ans = 1;
            return;
        }
    }
}

void out()
{
    //ofstream cout("A.out");
    ans ? cout << "YES\n" : cout << "NO\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
