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

#define IN_NAME "problem4.in"
#define OUT_NAME "problem4.out"

using namespace std;

const int MAXN = 100 + 15, MOD = (int)1e9 + 7;

int n, m, k, L, ans;
VEC <VEC <int>> gr;
VEC <LL> dp;

void in()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin(IN_NAME);
    cin >> n >> m >> k >> L;
    dp.resize(n + 5);
    gr.resize(n + 5);
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        dp[a] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        gr[a].PB(b);
    }
}

void solution()
{
    for (int len = 0; len < L; ++len) {
        VEC <LL> tmpDp(n + 5);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < gr[i].SZ; ++j) {
                int to = gr[i][j];
                tmpDp[i] = (tmpDp[i] + dp[to]) % MOD;
            }
        }
        dp = tmpDp;
    }
    ans = dp[1];
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
