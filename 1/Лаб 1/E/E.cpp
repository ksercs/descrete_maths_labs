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

const int MAXN = 30;

int n, ans, root, k;
int st[MAXN];
VEC <VEC <int> > tabl;
VEC <VEC <int> > dep;
VEC <int> leaf;
set <int> u;
int val[MAXN];

void in()
{
    //ifstream cin("E.in");
    cin >> n;
    tabl.resize(n+1);
    dep.resize(n+1);
    for (int i = 1; i <= n; ++i){
        int m;
        cin >> m;
        dep[i].resize(m);
        for (int j = 0; j < m; ++j){
            cin >> dep[i][j];
            st[i] = max(st[i], st[dep[i][j]]);
        }
        ++st[i];
        if (ans < st[i]){
            ans = st[i];
            root = i;
        }
        if (!m) continue;
        tabl[i].resize((1<<m));
        for (int j = 0; j < (1<<m); ++j){
            cin >> tabl[i][j];
        }
    }
}

void solution()
{
    --ans;
    for (int i = 1; i <= n; ++i){
        if (st[i] == 1){
            leaf.PB(i);
            u.insert(i);
        }
    }
    k = leaf.SZ;
}

int getAns (int v)
{
    //cout << v << "\n";
    if (val[v] || u.count(v))
        return val[v];
    int res = 0;
    for (int i = 0; i < dep[v].SZ; ++i){
        res += getAns(dep[v][i])*(1<<(dep[v].SZ-i-1));
    }
    //cout << "RES = " << res << " " << tabl[v][res] << "\n";
    return tabl[v][res];
}

void out()
{
    //ofstream cout("E.out");
    cout << ans << "\n";
    for (int i = 0; i < (1<<k); ++i){
        memset(val, 0, sizeof(val));
        int ch = k-1;
        for (int j = 0; j < k; ++j){
            val[leaf[j]] = ((i&(1<<ch))>0);
            //cout << val[leaf[j]] << " ";
            --ch;
        }
        //cout << "\n";
        cout << getAns(root);
        /*cout << "ans = " << getAns(root) << "\n";
        for (int i = 1; i <= n; ++i)
            cout << val[i] << " ";
        cout << "\n";*/ //system("PAUSE");
    }
    cout << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
