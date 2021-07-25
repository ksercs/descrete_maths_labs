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

#define IN_NAME "problem3.in"
#define OUT_NAME "problem3.out"

using namespace std;

const int MAXN = (int)1e5 + 15, MOD = (int)1e9 + 7;

int n, m, k, ans;
VEC <VEC <int>> gr, reverseGr;
bool isTerm[MAXN], isAttainableFromStart[MAXN], isAttainableFromTerm[MAXN];
int u[MAXN];
LL dp[MAXN];
VEC <int> term;

void findAttainableFromStart(int v) {
    u[v] = 1;
    isAttainableFromStart[v] = 1;
    for (int i = 0; i < gr[v].SZ; ++i) {
        int to = gr[v][i];
        if ( !u[to] )
            findAttainableFromStart(to);
    }
}

void findAttainableFromTerm(int v) {
    u[v] = 2;
    isAttainableFromTerm[v] = 1;
    for (int i = 0; i < reverseGr[v].SZ; ++i) {
        int to = reverseGr[v][i];
        if (u[to] != 2) {
            findAttainableFromTerm(to);
        }
    }
}
int fl = 0;

LL getAns (int v) {
    if (!isAttainableFromTerm[v])
        return 0;
    if (u[v] == 4) {
        return dp[v];
    }
    u[v] = 3;

    for (int i = 0; i < gr[v].SZ; ++i) {
        int to = gr[v][i];
        if (u[to] == 3 ) {
            fl = 1;
            return -1;
        }
        //p[to] = v;
        dp[v] = (dp[v] + getAns(to)) % MOD;
        if (fl)
            return -1;
    }

    if (isTerm[v]) {
        dp[v] = (dp[v] + 1) % MOD;
    }
    u[v] = 4;
    //cout << v << " : " << dp[v] << "\n";
    return dp[v];
}

void in()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin(IN_NAME);
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        isTerm[a] = 1;
        term.PB(a);
    }
    gr.resize(n  + 15);
    reverseGr.resize(n + 15);
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        gr[a].PB(b);
        reverseGr[b].PB(a);
    }
}

void solution()
{
    findAttainableFromStart(1);

    for (int i = 0; i < k; ++i) {
        findAttainableFromTerm(term[i]);
    }

    ans = getAns(1);
}

void out()
{
    cout.tie(0);
    ofstream cout(OUT_NAME);
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
