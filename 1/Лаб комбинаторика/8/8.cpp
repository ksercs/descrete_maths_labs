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

int n, st = 1, k;
int u[20];

VEC <int> el;
VEC <VEC <int>> ans;

void dfs_R(int ind)
{
    if (ind == k){
        ans.PB(el);
        return;
    }
    for (int i = st; i <= n; ++i) {
        if (!u[i]) {
            u[i] = 1;
            st = i;
            el[ind] = i;
            dfs_R(ind+1);
            u[i] = 0;
        }
    }
}

void in()
{
    ifstream cin ("choose.in");
    cin >> n >> k;
}

void solution()
{
    for (int i = 1; i <= k; i++) {
        el.PB(0);
    }
    dfs_R(0);
}

void out()
{
     ofstream cout ("choose.out");
     for (int i = 0; i < ans.SZ; ++i) {
         for (int j = 0; j < ans[i].SZ; ++j)
            cout << ans[i][j] << " ";
         cout << "\n";
     }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
