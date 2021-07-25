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

const int MAXN = 20 + 5;

int n, k, fl;
int u[MAXN];
VEC <VEC <int>> ans;

void out()
{
    if (fl)
        cout << "\n";
    for (int i = 0; i < k; ++i){
        for (int j = 0; j < ans[i].SZ; ++j)
            cout << ans[i][j] << " ";
            cout << "\n";
    }
    fl = 1;
}

void dfs (int emp, int maxi)
{
    //cout << "dfs: " << emp << " "<< maxi << "\n";
   // cout << "ANS = " << ans[0][0] << " " << ans[1][0] << "\n";
    if (!emp) {
        out();
        return;
    }
    for (int i = 0; i < k; ++i){
        int st = maxi;
        if (st < ans[i].back())
            st = ans[i].back();
        ++st;
        for (int j = st; j <= n; ++j){
            if (!u[j]) {
                ans[i].PB(j);
                u[j] = 1;
                dfs(emp-1, j);
                u[j] = 0;
                ans[i].pop_back();
            }
        }
    }
}

void DFS(int ind, int maxi)
{
   // cout << "DFS : " << ind << " " << maxi << "\n";
    if (ind == k)
        dfs(n-k, 0);
    else
        for (int i = maxi; i <= n; ++i){
            ans[ind].PB(i);
            u[i] = 1;
            DFS(ind+1, i+1);
            u[i] = 0;
            ans[ind].pop_back();
        }
}

void in()
{
    cin >> n >> k;
}

void solution()
{
    ans.resize(k);
    DFS(0, 1);
}

int main()
{
    freopen("part2sets.in", "r", stdin);
    freopen("part2sets.out", "w", stdout);
    in();
    solution();
    return 0;
}
